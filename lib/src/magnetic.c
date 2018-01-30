#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mruby.h"
#include "mruby/compile.h"
#include "mruby/value.h"
#include "mruby/array.h"
#include "mruby/string.h"
#include "mruby/hash.h"

/*#include "gedi.h"*/

static mrb_value
mrb_magnetic_s__read(mrb_state *mrb, mrb_value self)
{
  /*mrb_int ret;*/
  mrb_value hash;

  /*BYTE abTk1[256], abTk2[256], abTk3[256];*/
  /*UINT uiLen1 = 0,uiLen2 = 0,uiLen3 = 0 ;*/

  /*uiLen1 = sizeof(abTk1);*/
  /*uiLen2 = sizeof(abTk2);*/
  /*uiLen3 = sizeof(abTk3);*/

  /*ret = GEDI_MSR_Read(abTk1, &uiLen1, abTk2, &uiLen2, abTk3, &uiLen3);*/

  hash = mrb_hash_new(mrb);
  /*mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_cstr(mrb, "ret")), mrb_fixnum_value(ret));*/

  /*if (ret == GEDI_MSR_STATUS_SUCCESS) {*/
    /*mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_cstr(mrb, "track1")), mrb_str_new(mrb, abTk1, uiLen1));*/
    /*mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_cstr(mrb, "track2")), mrb_str_new(mrb, abTk2, uiLen2));*/
    /*mrb_hash_set(mrb, hash, mrb_symbol_value(mrb_intern_cstr(mrb, "track3")), mrb_str_new(mrb, abTk3, uiLen3));*/
  /*}*/

  return hash;
}

void
mrb_magnetic_init(mrb_state* mrb)
{
  struct RClass *platform;
  struct RClass *magnetic;

  platform = mrb_class_get(mrb, "Platform");
  magnetic = mrb_define_class_under(mrb, platform, "Magnetic", mrb->object_class);

  mrb_define_class_method(mrb , magnetic , "_read" , mrb_magnetic_s__read , MRB_ARGS_NONE());
}

