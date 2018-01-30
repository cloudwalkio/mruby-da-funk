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

/*int font_height;*/
/*int font_width;*/

/*int display_columns=0;*/
/*char display_space[50]="\0";*/

/*static void*/
/*set_display_columns(mrb_state *mrb, mrb_value self)*/
/*{*/
  /*mrb_value screen;*/
  /*mrb_int i;*/

  /*memset(&display_space, 0, sizeof(display_space));*/

  /*screen          = mrb_const_get(mrb, mrb_obj_value(mrb->object_class), mrb_intern_lit(mrb, "STDOUT"));*/
  /*display_columns = mrb_fixnum(mrb_funcall(mrb, screen, "max_x", 0));*/

  /*for (i = 0; i < display_columns; ++i ) strcat(display_space, " ");*/
/*}*/

static mrb_value
mrb_display_s_clear(mrb_state *mrb, mrb_value self)
{
  /*GEDI_LCD_Clear();*/
  return mrb_nil_value();
}

static mrb_value
mrb_display_s_clear_line(mrb_state *mrb, mrb_value self)
{
  /*mrb_int line;*/
  /*mrb_get_args(mrb, "i", &line);*/

  /*if (display_columns == 0) set_display_columns(mrb, self);*/

  /*GEDI_LCD_DrawString(0, line*font_height, font_width, font_height, display_space);*/
  return mrb_nil_value();
}

static mrb_value
mrb_display_s_print_bitmap(mrb_state *mrb, mrb_value self)
{
  /*mrb_value path;*/
  /*mrb_int x, y;*/

  /*mrb_get_args(mrb, "Sii", &path, &y, &x);*/

  /*GEDI_LCD_DrawPictureFromFile(x, y, RSTRING_PTR(path), GEDI_FS_STORAGE_PRIVATE);*/

  return mrb_nil_value();
}

/*
  retrieve arguments from mrb_state.
  mrb_get_args(mrb, format, ...)
  returns number of arguments parsed.
  format specifiers:
    string  mruby type     C type                 note
    ----------------------------------------------------------------------------------------------
    o:      Object         [mrb_value]
    C:      class/module   [mrb_value]
    S:      String         [mrb_value]
    A:      Array          [mrb_value]
    H:      Hash           [mrb_value]
    s:      String         [char*,mrb_int]        Receive two arguments.
    z:      String         [char*]                NUL terminated string.
    a:      Array          [mrb_value*,mrb_int]   Receive two arguments.
    f:      Float          [mrb_float]
    i:      Integer        [mrb_int]
    b:      Boolean        [mrb_bool]
    n:      Symbol         [mrb_sym]
    d:      Data           [void*,mrb_data_type const] 2nd argument will be used to check data type so it won't be modified
    &:      Block          [mrb_value]
    *:      rest argument  [mrb_value*,mrb_int]   Receive the rest of the arguments as an array.
    |:      optional                              Next argument of '|' and later are optional.
    ?:      optional given [mrb_bool]             true if preceding argument (optional) is given.
 */

static mrb_value
mrb_display_s_print_line(mrb_state *mrb, mrb_value self)
{
  /*mrb_value buf;*/
  /*mrb_int x, y;*/

  /*mrb_get_args(mrb, "Sii", &buf, &y, &x);*/

  /*GEDI_LCD_DrawString(x*font_width,y*font_height,font_width,font_height,(const CHAR *)RSTRING_PTR(buf));*/

  return mrb_nil_value();
}

static mrb_value
mrb_display_s_print_status_bar(mrb_state *mrb, mrb_value self)
{
  return mrb_true_value();
}

static mrb_value
mrb_display_s_status_bar_slots_available(mrb_state *mrb, mrb_value self)
{
  return mrb_fixnum_value(0);
}

void
mrb_display_init(mrb_state* mrb)
{
  struct RClass *platform;
  struct RClass *display;

  platform = mrb_class_get(mrb, "Platform");
  display = mrb_define_class_under(mrb, platform, "Display", mrb->object_class);

  mrb_define_class_method(mrb , display , "clear"                      , mrb_display_s_clear                      , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , display , "clear_line"                 , mrb_display_s_clear_line                 , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , display , "print_bitmap"               , mrb_display_s_print_bitmap               , MRB_ARGS_REQ(3));
  mrb_define_class_method(mrb , display , "print_line"                 , mrb_display_s_print_line                 , MRB_ARGS_REQ(3));
  mrb_define_class_method(mrb , display , "print_status_bar"           , mrb_display_s_print_status_bar           , MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb , display , "status_bar_slots_available" , mrb_display_s_status_bar_slots_available , MRB_ARGS_NONE());
}
