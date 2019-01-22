#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#define __ELF_WORD_SIZE 32

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
#include <compat/freebsd32/freebsd32_proto.h>

int
freebsd32_panicer(struct thread *td,
		  struct freebsd32_panicer_args *uap)
{
  sprintf(uap->buf, "HELLO");
  td->td_retval[0] = 0;
  return 0;
}
