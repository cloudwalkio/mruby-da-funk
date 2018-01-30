#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/variable.h"
#include "mruby/string.h"
#include "mruby/hash.h"

/*#include "gedi.h"*/

static mrb_value
mrb_smart_s_status(mrb_state *mrb, mrb_value self)
{
  /*mrb_int slot, status=0, ret;*/
  /*mrb_value array;*/

  /*mrb_get_args(mrb, "i", &slot);*/

  /*ret = GEDI_SMART_Status(slot, &status);*/

  array = mrb_ary_new(mrb);
  /*mrb_ary_push(mrb, array, mrb_fixnum_value(ret));*/
  /*mrb_ary_push(mrb, array, mrb_fixnum_value(status));*/

  return array;
}

void
mrb_smart_card_init(mrb_state* mrb)
{
  struct RClass *platform;
  struct RClass *smart;

  platform = mrb_class_get(mrb, "Platform");
  smart = mrb_define_class_under(mrb, platform, "SmartCard", mrb->object_class);

  mrb_define_class_method(mrb , smart , "status" , mrb_smart_s_status , MRB_ARGS_REQ(1));
}