#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"
/*#include <gedi.h>*/

static mrb_value
mrb_platform_io_s__getc(mrb_state *mrb, mrb_value self)
{
  /*mrb_int timeout=0, ret=0;*/
  /*GEDI_KBD_e_Key eKey=1, eKeyClear=1;*/

  /*mrb_get_args(mrb, "i", &timeout);*/

  /*if (!timeout) timeout = INFINITE;*/
  /*ret = GEDI_KBD_Get(&eKey, timeout, FALSE);*/

  /*if (ret != 0) eKey = 1;*/

  /*return mrb_fixnum_value(eKey);*/
  return mrb_fixnum_value(0);
}

void
mrb_io_init(mrb_state* mrb)
{
  struct RClass *io;

  io = mrb_class_get(mrb, "IO");

  mrb_define_class_method(mrb , io , "_getc" , mrb_platform_io_s__getc , MRB_ARGS_REQ(1));
}
