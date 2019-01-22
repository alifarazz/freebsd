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

#include <sys/sysproto.h>
#include <sys/syscall.h>

/* #include <stdio.h> */


#ifndef _SYS_SYSPROTO_H_
struct panicer_args{
  char *buf;
};
#endif

int
sys_panicer(struct thread *td, struct panicer_args *uap)
{
  sprintf(uap->buf, "HELLO");
  td->td_retval[0] = 0;
  return 0;
}
