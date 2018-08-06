#include <stdlib.h>
#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"

static mrb_value
mrb_touch_s__getxy(mrb_state *mrb, mrb_value self)
{
  /*mrb_int x = 0, y = 0, ret = 0, timeout = 0;*/
  mrb_value hash;

  /*mrb_get_args(mrb, "i", &timeout);*/

  /*ret = TouchGet(&x, &y, &event, timeout, TRUE);*/

  hash = mrb_hash_new(mrb);
  /*if ((ret == 0) && (event == 1)) {*/
    /*mrb_hash_set(mrb , hash , mrb_str_new_lit(mrb , "x")      , mrb_fixnum_value(x));*/
    /*mrb_hash_set(mrb , hash , mrb_str_new_lit(mrb , "y")      , mrb_fixnum_value(y));*/
    /*mrb_hash_set(mrb , hash , mrb_str_new_lit(mrb , "return") , mrb_fixnum_value(ret));*/
  /*}*/

  return hash;
}

static mrb_value
mrb_touch_s__getxy_stream(mrb_state *mrb, mrb_value self)
{
  /*mrb_int x = 0, y = 0, ret = 0, timeout = 0;*/
  mrb_value hash;

  /*mrb_get_args(mrb, "i", &timeout);*/

  /*ret = TouchGet(&x, &y, &event, timeout, TRUE);*/

  hash = mrb_hash_new(mrb);
  /*if ((ret == 0) && (event == 1)) {*/
    /*mrb_hash_set(mrb , hash , mrb_str_new_lit(mrb , "x")      , mrb_fixnum_value(x));*/
    /*mrb_hash_set(mrb , hash , mrb_str_new_lit(mrb , "y")      , mrb_fixnum_value(y));*/
    /*mrb_hash_set(mrb , hash , mrb_str_new_lit(mrb , "return") , mrb_fixnum_value(ret));*/
  /*}*/

  return hash;
}

void
mrb_touch_init(mrb_state* mrb)
{
  struct RClass *platform, *touch;

  platform = mrb_define_class(mrb, "Platform", mrb->object_class);
  touch    = mrb_define_class_under(mrb, platform, "Touch", mrb->object_class);

  mrb_define_class_method(mrb , touch , "_getxy" , mrb_touch_s__getxy , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , touch , "_getxy_stream" , mrb_touch_s__getxy , MRB_ARGS_REQ(1));
}
