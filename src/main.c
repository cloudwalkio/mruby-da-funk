#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

/* Include the mruby header */
#include "mruby.h"
#include "mruby/value.h"
#include "mruby/compile.h"
#include "mruby/proc.h"

/* Include the mruby header */
#include "mruby.h"
#include "mruby/value.h"
#include "mruby/compile.h"
#include "mruby/proc.h"

void context_memprof_init(mrb_allocf *funp, void **udp);

int main(void)
{
	char code[] = "Context.start(\"main\", \"Platform\")";
  mrbc_context *c;
  mrb_state *mrb;
  mrb_allocf allocf;
  void *ud;

  context_memprof_init(&allocf, &ud);

  mrb = mrb_open_allocf(allocf, ud);

  c = mrbc_context_new(mrb);

	mrb_load_string_cxt(mrb, code, c);

  mrbc_context_free(mrb, c);

  mrb_close(mrb);

  return 0;
}

