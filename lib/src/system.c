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
mrb_system_s_serial(mrb_state *mrb, mrb_value self)
{
  char serial[20];

  /*memset(serial, 0, sizeof(serial));*/
  /*GEDI_INFO_ControlNumberGet(GEDI_INFO_CONTROL_NUMBER_SN, serial);*/

  return mrb_str_new_cstr(mrb, serial);
}

static mrb_value
mrb_system_s__set_backlight(mrb_state *mrb, mrb_value self)
{
  mrb_int mode=0;

  /*mrb_get_args(mrb, "i", &mode);*/

  /*GEDI_LCD_ContrastSet(mode);*/

  /*GEDI_LED_Set(GEDI_LED_ID_BACKLIGHT_KEYBOARD , 0);*/

  /*if (mode == 0) {*/
    /*GEDI_LED_Set(GEDI_LED_ID_BACKLIGHT_DISPLAY  , 0);*/
  /*} else {*/
    /*GEDI_LED_Set(GEDI_LED_ID_BACKLIGHT_DISPLAY  , 1);*/
  /*}*/

  return mrb_fixnum_value(mode);
}

static mrb_value
mrb_system_s_battery(mrb_state *mrb, mrb_value self)
{
  /*UINT puiPercentage;*/

  /*GEDI_POWER_BatteryGetCapacity (&puiPercentage);*/

  return mrb_fixnum_value(0);
}

static mrb_value
mrb_s__power_supply(mrb_state *mrb, mrb_value self)
{
  /*GEDI_POWER_e_Src supply = 0;*/

  /*GEDI_POWER_SourceGet(&supply);*/

  /*if (supply == 0)*/
    return mrb_true_value();
  /*else*/
    /*return mrb_false_value();*/
}

static mrb_value
mrb_audio_s__beep(mrb_state *mrb, mrb_value self)
{
  /*mrb_int tone, milliseconds;*/

  /*mrb_get_args(mrb, "ii", &tone, &milliseconds);*/

  /*GEDI_AUDIO_PlayNote (0, tone, milliseconds);*/

  return mrb_nil_value();
}

static mrb_value
mrb_system_s_reboot(mrb_state *mrb, mrb_value self)
{
  mrb_int ret=0;

  /*ret = GEDI_POWER_Reset ();*/

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_system_s_hwclock(mrb_state *mrb, mrb_value self)
{
  /*mrb_value timezone;*/
  /*mrb_int year, month, day, hour, minute, second;*/
  /*GEDI_CLOCK_st_RTC stRTC;*/

  /*mrb_get_args(mrb, "iiiiiio", &year, &month, &day, &hour, &minute, &second, &timezone);*/

  /*stRTC.bYear   = year-2000;*/
  /*stRTC.bMonth  = month;*/
  /*stRTC.bDay    = day;*/
  /*stRTC.bHour   = hour;*/
  /*stRTC.bMinute = minute;*/
  /*stRTC.bSecond = second;*/

  /*return mrb_fixnum_value(GEDI_CLOCK_RTCSet(&stRTC));*/
  return mrb_fixnum_value(0);
}

static mrb_value
mrb_system_s_model(mrb_state *mrb, mrb_value self)
{
  char szName[21]="\0";

  /*GEDI_INFO_ProductNameGet((CHAR *)&szName);*/

  return mrb_funcall(mrb, mrb_str_new_cstr(mrb, szName), "downcase", 0);
}

static mrb_value
mrb_system_s_brand(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "platform");
}

static mrb_value
mrb_system_s_os_version(mrb_state *mrb, mrb_value self)
{
  char version[21]="\0";

  /*GEDI_INFO_FirmwareVersionGet((CHAR *)&version);*/

  return mrb_str_new_cstr(mrb, version);
}

static mrb_value
mrb_system_s_sdk_version(mrb_state *mrb, mrb_value self)
{
  char version[32]="\0";
  /*unsigned int major=0,minor=0,release=0,build=0;*/

  /*GEDI_VersionGet(&major, &minor, &release, &build);*/

  /*sprintf(version, "%d.%d.%d.%d", major, minor, release, build);*/

  return mrb_str_new_cstr(mrb, version);
}

static mrb_value
mrb_system_s_pinpad_version(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "0");
}

static mrb_value
mrb_system_s_install(mrb_state *mrb, mrb_value self)
{
  /*mrb_int type;*/
  /*mrb_value path, name;*/

  /*mrb_get_args(mrb, "SSi", &name, &path, &type);*/

  /*return mrb_fixnum_value(GEDI_PM_UpdateFromFile(RSTRING_PTR(path), (GEDI_FS_e_Storage)type));*/
  return mrb_fixnum_value(0);
}

static mrb_value
mrb_system_s_get_time(mrb_state *mrb, mrb_value self)
{
  /*mrb_int year;*/
  mrb_value array;
  /*GEDI_CLOCK_st_RTC stRTC;*/

  /*GEDI_CLOCK_RTCGet(&stRTC);*/

  array  = mrb_ary_new(mrb);
  /*year = (2000 + stRTC.bYear > 2100) ? 2020 : 2000 + stRTC.bYear;*/
  /*mrb_ary_push(mrb, array, mrb_fixnum_value(year));*/
  /*mrb_ary_push(mrb, array, mrb_fixnum_value(stRTC.bMonth));*/
  /*mrb_ary_push(mrb, array, mrb_fixnum_value(stRTC.bDay));*/
  /*mrb_ary_push(mrb, array, mrb_fixnum_value(stRTC.bHour));*/
  /*mrb_ary_push(mrb, array, mrb_fixnum_value(stRTC.bMinute));*/
  /*mrb_ary_push(mrb, array, mrb_fixnum_value(stRTC.bSecond));*/

  return array;
}

static mrb_value
mrb_system_s_status_bar(mrb_state *mrb, mrb_value self)
{
  /*mrb_value bg, wifi, gprs, battery;*/

  /*mrb_get_args(mrb, "SSSS", &bg, &wifi, &gprs, &battery);*/

  /*GEDI_LCD_StatusBarSetIconFromFile(GEDI_LCD_ICON_EMPTY      , RSTRING_PTR(bg)      , GEDI_FS_STORAGE_PRIVATE);*/
  /*GEDI_LCD_StatusBarSetIconFromFile(GEDI_LCD_ICON_WIFI       , RSTRING_PTR(wifi)    , GEDI_FS_STORAGE_PRIVATE);*/
  /*GEDI_LCD_StatusBarSetIconFromFile(GEDI_LCD_ICON_GSM_SIGNAL , RSTRING_PTR(gprs)    , GEDI_FS_STORAGE_PRIVATE);*/
  /*GEDI_LCD_StatusBarSetIconFromFile(GEDI_LCD_ICON_BATTERY    , RSTRING_PTR(battery) , GEDI_FS_STORAGE_PRIVATE);*/

  /*GEDI_LCD_StatusBarShow(GEDI_LCD_STATUSBARPOSITION_TOP, 1, "i i i", GEDI_LCD_ICON_BATTERY, GEDI_LCD_ICON_GSM_SIGNAL, GEDI_LCD_ICON_WIFI);*/

  return mrb_true_value();
}

void
mrb_system_init(mrb_state* mrb)
{
  struct RClass *platform;
  struct RClass *audio;
  struct RClass *system;

  platform = mrb_define_class(mrb, "Platform", mrb->object_class);
  audio    = mrb_define_class_under(mrb, platform, "Audio", mrb->object_class);
  system   = mrb_define_class_under(mrb, platform, "System", mrb->object_class);

  mrb_define_class_method(mrb , system , "serial"         , mrb_system_s_serial         , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "backlight="     , mrb_system_s__set_backlight , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , system , "battery"        , mrb_system_s_battery        , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "_power_supply"  , mrb_s__power_supply         , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , audio  , "beep"           , mrb_audio_s__beep           , MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb , system , "reboot"         , mrb_system_s_reboot         , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "hwclock"        , mrb_system_s_hwclock        , MRB_ARGS_REQ(7));
  mrb_define_class_method(mrb , system , "model"          , mrb_system_s_model          , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "brand"          , mrb_system_s_brand          , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "os_version"     , mrb_system_s_os_version     , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "sdk_version"    , mrb_system_s_sdk_version    , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "pinpad_version" , mrb_system_s_pinpad_version , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "install"        , mrb_system_s_install        , MRB_ARGS_REQ(3));
  mrb_define_class_method(mrb , system , "get_time"       , mrb_system_s_get_time       , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , system , "status_bar"     , mrb_system_s_status_bar     , MRB_ARGS_REQ(4));
}
