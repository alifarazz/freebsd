#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#define __ELF_WORD_SIZE 32

#ifdef COMPAT_FREEBSD11
#define	_WANT_FREEBSD11_KEVENT
#endif

#include <sys/param.h>
#include <sys/syscall.h>
#include <sys/syscallsubr.h>


#include <sys/proc.h>
#include <sys/procctl.h>
#include <sys/sysproto.h>
#include <sys/systm.h>
#include <sys/thr.h>
#include <sys/unistd.h>

#include <compat/freebsd32/freebsd32_util.h>
#include <compat/freebsd32/freebsd32.h>
#include <compat/freebsd32/freebsd32_ipc.h>
#include <compat/freebsd32/freebsd32_misc.h>
#include <compat/freebsd32/freebsd32_signal.h>
#include <compat/freebsd32/freebsd32_proto.h>

FEATURE(compat_freebsd_32bit, "Compatible with 32-bit FreeBSD");

#ifdef __amd64__
CTASSERT(sizeof(struct timeval32) == 8);
CTASSERT(sizeof(struct timespec32) == 8);
CTASSERT(sizeof(struct itimerval32) == 16);
CTASSERT(sizeof(struct bintime32) == 12);
#endif
CTASSERT(sizeof(struct statfs32) == 256);
#ifdef __amd64__
CTASSERT(sizeof(struct rusage32) == 72);
#endif
CTASSERT(sizeof(struct sigaltstack32) == 12);
#ifdef __amd64__
CTASSERT(sizeof(struct kevent32) == 56);
#else
CTASSERT(sizeof(struct kevent32) == 64);
#endif
CTASSERT(sizeof(struct iovec32) == 8);
CTASSERT(sizeof(struct msghdr32) == 28);
#ifdef __amd64__
CTASSERT(sizeof(struct stat32) == 208);
CTASSERT(sizeof(struct freebsd11_stat32) == 96);
#endif
CTASSERT(sizeof(struct sigaction32) == 24);


// sys_panicer sys/kern/kern_panicer.c
int
freebsd32_panicer(struct thread *td,
		  struct freebsd32_panicer_args *uap)
{
  sprintf(uap->buf, "HELLO");
  td->td_retval[0] = 0;
  return 0;
}
