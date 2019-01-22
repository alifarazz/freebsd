#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/param.h>
#include <sys/systm.h>
/* #include <sys/cpuset.h> */
/* #include <sys/kthread.h> */
/* #include <sys/kernel.h> */
/* #include <sys/lock.h> */
/* #include <sys/mutex.h> */
#include <sys/proc.h>
/* #include <sys/resourcevar.h> */
/* #include <sys/rwlock.h> */
/* #include <sys/signalvar.h> */
/* #include <sys/sx.h> */
/* #include <sys/umtx.h> */
/* #include <sys/unistd.h> */
/* #include <sys/wait.h> */
/* #include <sys/sched.h> */
/* #include <sys/tslog.h> */
/* #include <vm/vm.h> */
/* #include <vm/vm_extern.h> */

/* #include <machine/stdarg.h> */

#include <sys/syscall.h>
#include <sys/sysproto.h>

#ifndef _SYS_SYSPROTO_H_
struct panicer_args {
  int which;
  int who;
  int nice_offset;
};
struct setpriority_args {
  int which;
  int who;
  int prio;
};
struct getpriority_args {
  int which;
  int who;
};
#endif

/**********************************/
/* return values:                 */
/* -1: on failure to get priority */
/* -2: on failure to set priority */
/**********************************/
int
sys_bump_prio(struct thread *td, struct bump_prio_args *uap)
{
  struct getpriority_args getprio_args;
  struct setpriority_args setprio_args;
  int ret_sys_getpriorty;
  int ret_sys_setpriority;

  /* set getprio args */
  getprio_args.which = uap->which;
  getprio_args.who = uap->who;

  /* call and check sys_getpriority */
  ret_sys_getpriorty = sys_getpriority(td, &getprio_args);
  if (td->td_retval[0] == -1 ||
      ret_sys_getpriorty == -1) { /* error on sys_getprioriy */
    /* td->td_retval[0] = -1; // kinda useless */
    return -1;
  }

  /* set setprio args */
  setprio_args.which = uap->which;
  setprio_args.who = uap->who;
  setprio_args.prio = td->td_retval[0] + uap->nice_offset; /* add nice offset */

  /* call and check sys_priority */
  ret_sys_setpriority = sys_setpriority(td, &setprio_args);
  if (td->td_retval[0] == -1 ||
      ret_sys_setpriorty == -1) { /* error on sys_setpriority */
    td->td_retval[0] = -2;
    return -2;
  }

  /* if sys_setpriority call is successful, td->td-retval[0] will be untouched
   */
  return 0;
}
