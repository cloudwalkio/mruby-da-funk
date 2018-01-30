#include "mruby.h"
#include <string.h>
#include <stddef.h>


#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/hash.h"
#include "mruby/string.h"
#include "mruby/variable.h"
//#include "Utils/KeyBoardMan.h"

/*#include "gedi.h"*/

/*GEDI_KBD_e_Key eKey_w;*/

#if MRUBY_RELEASE_NO < 10000
  #include "error.h"
#else
  #include "mruby/error.h"
#endif

static mrb_value
mrb_wifi_start(mrb_state *mrb, mrb_value klass)
{
  mrb_int ret=0, attempts=0;

  /*GEDI_GSM_Disable();*/
  /*GEDI_WIFI_Disable();*/
  /*do {*/
    /*ret = GEDI_WIFI_Enable ();*/
    /*GEDI_CLOCK_Delay(500);*/
    /*attempts++;*/
  /*} while (ret!=0 && attempts < 20);*/

  return mrb_fixnum_value(ret);
}

/*Turn on/off the power 1 - on 0 - off*/
static mrb_value
mrb_wifi_power(mrb_state *mrb, mrb_value klass)
{
  mrb_int state, ret=0, attempts = 0;
  /*mrb_get_args(mrb, "i", &state);*/

  /*if(state) {*/
    /*do {*/
      /*attempts++;*/
      /*ret = GEDI_WIFI_Enable();*/
      /*GEDI_CLOCK_Delay(500);*/
    /*} while (ret!=0 && attempts < 20);*/
  /*} else {*/
    /*ret = GEDI_WIFI_Disable();*/
  /*}*/

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_wifi_connect(mrb_state *mrb, mrb_value klass)
{
  /*mrb_value password, essid, channel, mode, authentication, cipher;*/
  /*char *sPassword, *sChannel, *sCipher, *sAuthentication;*/

  /*GEDI_WIFI_st_Info wifi_conf;*/

  /*memset(&wifi_conf, 0, sizeof(wifi_conf));*/

  /*GEDI_WIFI_APDisconnect();*/
  /*GEDI_WIFI_Disable();*/
  /*GEDI_WIFI_Enable();*/

  /*essid = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@essid"));*/
  /*strcpy((char *)wifi_conf.ESSID, mrb_str_to_cstr(mrb, essid));*/

  /*password = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@password"));*/
  /*sPassword = mrb_str_to_cstr(mrb, password);*/

  /*channel = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@channel"));*/
  /*sChannel = mrb_str_to_cstr(mrb, channel);*/
  /*sprintf((char *)wifi_conf.Freq, "2.4%02d GHz (Channel %d)", 7 + (5 * atoi(sChannel)), atoi(sChannel));*/

  /*mode = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@mode"));*/
  /*strcpy((char *)wifi_conf.Mode, mrb_str_to_cstr(mrb, mode));*/

  /*cipher = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@cipher"));*/
  /*sCipher = mrb_str_to_cstr(mrb, cipher);*/

  /*authentication = mrb_cv_get(mrb, klass, mrb_intern_lit(mrb, "@authentication"));*/
  /*sAuthentication = mrb_str_to_cstr(mrb, authentication);*/

  /*if (strcmp(sAuthentication, "") == 0)*/
  /*{*/
    /*strcpy((char *)wifi_conf.EncryptionKey, "off");*/
    /*strcpy((char *)wifi_conf.Type_1, " ");*/
    /*strcpy((char *)wifi_conf.Authentication_1, " ");*/
  /*}*/
  /*else if (strcmp(sAuthentication, "wpapsk") == 0)*/
  /*{*/
    /*strcpy((char *)wifi_conf.EncryptionKey, "on");*/
    /*strcpy((char *)wifi_conf.Type_1, "WPA");*/
    /*strcpy((char *)wifi_conf.Authentication_1, "PSK");*/
  /*}*/
  /*else if (strcmp(sAuthentication, "wpa2psk") == 0)*/
  /*{*/
    /*strcpy((char *)wifi_conf.EncryptionKey, "on");*/
    /*strcpy((char *)wifi_conf.Type_1, "WPA2");*/
    /*strcpy((char *)wifi_conf.Authentication_1, "PSK");*/
  /*}*/

  /*if (strcmp(sCipher, "") == 0)*/
  /*{*/
    /*strcpy((char *)wifi_conf.GroupCipher_1, " ");*/
    /*strcpy((char *)wifi_conf.PairwiseCiphers_1, " ");*/
  /*}*/
  /*else if (strcmp(sCipher, "tkip") == 0)*/
  /*{*/
    /*strcpy((char *)wifi_conf.GroupCipher_1, "TKIP");*/
    /*strcpy((char *)wifi_conf.PairwiseCiphers_1, "TKIP");*/
  /*}*/
  /*else if (strcmp(sCipher, "ccmp") == 0)*/
  /*{*/
    /*strcpy((char *)wifi_conf.GroupCipher_1, "CCMP");*/
    /*strcpy((char *)wifi_conf.PairwiseCiphers_1, "CCMP");*/
  /*}*/
  /*else if (strcmp(sCipher, "ccmptki") == 0)*/
  /*{*/
    /*strcpy((char *)wifi_conf.GroupCipher_1, "TKIP");*/
    /*strcpy((char *)wifi_conf.PairwiseCiphers_1, "CCMPTKI");*/
  /*}*/
  /*GEDI_WIFI_ConfigSet(GEDI_WIFI_CONFIG_DHCP, "1");*/

  /*return mrb_fixnum_value(GEDI_WIFI_APConnect(&wifi_conf, sPassword));*/
  return mrb_fixnum_value(0);
}

/*0   -> Sucess */
/*1   -> In Progress*/
/*< 0 -> Fail*/
static mrb_value
mrb_wifi__connected_m(mrb_state *mrb, mrb_value klass)
{
  /*GEDI_WIFI_e_Status eStatus;*/

  /*GEDI_WIFI_Status(&eStatus);*/

  /*return mrb_fixnum_value(eStatus);*/
  return mrb_fixnum_value(0);
}

static mrb_value
mrb_wifi_disconnect(mrb_state *mrb, mrb_value klass)
{
  mrb_int ret = 0, attempts = 0, ret2 = 0;
  /*GEDI_WIFI_e_Status eStatus;*/

  /*GEDI_WIFI_APDisconnect();*/

  /*do {*/
		/*GEDI_CLOCK_Delay(500);*/
		/*GEDI_WIFI_Status(&eStatus);*/
    /*attempts++;*/
  /*} while (ret = (eStatus & GEDI_WIFI_STATUS_AP_DISCONNECTING) && attempts < 20);*/

  /*GEDI_WIFI_Disable();*/

  return mrb_fixnum_value(ret);
}

static mrb_value
mrb_wifi__scan(mrb_state *mrb, mrb_value klass)
{
  /*mrb_int i = 0, attempts = 0;*/
  /*UINT uiListSize = 0;*/
  /*GEDI_WIFI_st_Info *aps;*/
  /*GEDI_WIFI_e_Status peStatusMask;*/
  // mrb_value context;
  // char debug[1024];
  //
  // memset(debug, 0, sizeof(debug));
  // context = mrb_const_get(mrb, mrb_obj_value(mrb->object_class), mrb_intern_lit(mrb, "ContextLog"));
  // mrb_funcall(mrb, context, "info", 1, mrb_str_new_cstr(mrb, "inside mrb_wifi__scan"));

  /*GEDI_WIFI_Enable();*/
  /*GEDI_WIFI_Scan();*/

  /*do {*/
    /*attempts++;*/
    /*GEDI_WIFI_Status(&peStatusMask);*/
    /*GEDI_CLOCK_Delay(500);*/
  /*} while (peStatusMask == GEDI_WIFI_STATUS_SCANNING && attempts < 20);*/

  /*GEDI_WIFI_APListGet(&aps, &uiListSize);*/

  /*if (uiListSize < 0) return mrb_false_value();*/

  /*for (i = 0; i < uiListSize; i++) {*/
    /*mrb_funcall(mrb, klass, "ap", 9,*/
      /*mrb_str_new_cstr(mrb, (char *)aps[i].Address),*/
      /*mrb_str_new_cstr(mrb, (char *)aps[i].ESSID),*/
      /*mrb_str_new_cstr(mrb, (char *)aps[i].Mode),*/
      /*mrb_str_new_cstr(mrb, (char *)aps[i].Freq),*/
      /*mrb_str_new_cstr(mrb, (char *)aps[i].Quality),*/
      /*mrb_str_new_cstr(mrb, (char *)aps[i].Type_1),*/
      /*mrb_str_new_cstr(mrb, (char *)aps[i].GroupCipher_1),*/
      /*mrb_str_new_cstr(mrb, (char *)aps[i].PairwiseCiphers_1),*/
      /*mrb_str_new_cstr(mrb, (char *)aps[i].Authentication_1)*/
    /*);*/
  /*}*/
  return mrb_true_value();
}

void
mrb_wifi_init(mrb_state *mrb)
{
  struct RClass *platform, *network, *wifi;

  platform = mrb_class_get(mrb, "Platform");
  network  = mrb_class_get_under(mrb, platform, "Network");
  wifi     = mrb_define_class_under(mrb, network, "Wifi", mrb->object_class);

  mrb_define_class_method(mrb , wifi , "start"      , mrb_wifi_start       , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , wifi , "power"      , mrb_wifi_power       , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , wifi , "connect"    , mrb_wifi_connect     , MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb , wifi , "_connected?" , mrb_wifi__connected_m , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , wifi , "disconnect" , mrb_wifi_disconnect  , MRB_ARGS_NONE());
  mrb_define_class_method(mrb , wifi , "_scan"      , mrb_wifi__scan       , MRB_ARGS_NONE());
}

