#include <stdlib.h>
#include <stdio.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"
#include "mruby/data.h"
#include "mruby/class.h"
#include "mruby/variable.h"
/*#include "gedi.h"*/

/*#define FontH 20*/
/*#define FontW 20*/

static mrb_value
mrb_platform_printer_s__open(mrb_state *mrb, mrb_value self)
{
  mrb_int ret=0;

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_platform_printer_s__reset(mrb_state *mrb, mrb_value self)
{
  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__close(mrb_state *mrb, mrb_value self)
{
  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__font(mrb_state *mrb, mrb_value self)
{
  /*mrb_value filename;*/
  mrb_int ret=0;

  /*mrb_get_args(mrb, "S", &filename);*/

  /*ret = GEDI_PRNTR_FontSet(RSTRING_PTR(filename));*/

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_platform_printer_s__level(mrb_state *mrb, mrb_value self)
{
  /*mrb_int level=0;*/

  /*mrb_get_args(mrb, "i", &level);*/

  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__size(mrb_state *mrb, mrb_value self)
{
  /*mrb_int singlecode_width=0,singlecode_height=0,multicode_width=0,multicode_height=0;*/

  /*mrb_get_args(mrb, "iiii", &singlecode_width, &singlecode_height, &multicode_width, &multicode_height);*/

  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__feed(mrb_state *mrb, mrb_value self)
{
  /*mrb_int size;*/

  /*mrb_get_args(mrb, "i", &size);*/
  /*GEDI_PRNTR_Init(size*8);*/
  /*GEDI_PRNTR_Output();*/

  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__print(mrb_state *mrb, mrb_value self)
{
  /*mrb_value buf;*/
  /*mrb_int width=0, height=0;*/

  /*mrb_get_args(mrb, "S", &buf);*/

  /*height = mrb_fixnum(mrb_cv_get(mrb, self, mrb_intern_lit(mrb, "@single_height")));*/
  /*width  = mrb_fixnum(mrb_cv_get(mrb, self, mrb_intern_lit(mrb, "@single_width" )));*/

  /*GEDI_PRNTR_Init(height);*/
  /*GEDI_PRNTR_DrawString(0, 0, width, height, RSTRING_PTR(buf));*/
  /*GEDI_PRNTR_Output();*/
  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__print_bmp(mrb_state *mrb, mrb_value self)
{
  /*mrb_value path;*/

  /*mrb_get_args(mrb, "S", &path);*/

  /*GEDI_e_Ret eRet;*/
  /*GEDI_PRNTR_Init(160);*/
  /*eRet = GEDI_PRNTR_DrawPictureFromFile(0, 0, (const CHAR *)RSTRING_PTR(path), 50);*/
  /*GEDI_PRNTR_Output();*/
  /*GEDI_CLOCK_Delay(1000);*/

  return mrb_nil_value();
}

static mrb_value
mrb_platform_printer_s__check(mrb_state *mrb, mrb_value self)
{
  mrb_int ret=0;

  /*GEDI_PRNTR_Status(&ret);*/
  return mrb_fixnum_value(ret);
}

void
mrb_print_init(mrb_state* mrb)
{
  struct RClass *platform;
  struct RClass *print;

  platform = mrb_class_get(mrb, "Platform");
  print    = mrb_define_class_under(mrb, platform, "Printer", mrb->object_class);

  mrb_define_class_method(mrb , print , "_open"      , mrb_platform_printer_s__open      , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , print , "_reset"     , mrb_platform_printer_s__reset     , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , print , "_close"     , mrb_platform_printer_s__close     , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , print , "_font="     , mrb_platform_printer_s__font      , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , print , "_level="    , mrb_platform_printer_s__level     , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , print , "_size"      , mrb_platform_printer_s__size      , MRB_ARGS_REQ(4));
  mrb_define_class_method(mrb , print , "_feed"      , mrb_platform_printer_s__feed      , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , print , "_print"     , mrb_platform_printer_s__print     , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , print , "_print_bmp" , mrb_platform_printer_s__print_bmp , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , print , "_check"     , mrb_platform_printer_s__check     , MRB_ARGS_NONE());
}

