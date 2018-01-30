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

unsigned int crc_table[256];

void create_crc_table(void)
{
  int index;
  unsigned char counter;
  unsigned int data;
  uint16_t accumulator;

  for (index=0; index<256; index++)
  {
    data = index << 8;
    accumulator = 0;
    for (counter=1; counter<9; counter++)
    {
      if ( (( data ^ accumulator ) & 0x8000) == 0)
        accumulator = accumulator<<1;
      else
        accumulator = (accumulator<<1) ^ 0x1021;
      data = data << 1;
    }
    crc_table[index]=accumulator;
  }
}

static mrb_value
mrb_s_crc16(mrb_state *mrb, mrb_value klass)
{
  mrb_int accumulator;
  mrb_value buf;
  int index;
  unsigned char index2;
  int size;
  char *pbuf;

  mrb_get_args(mrb, "Si", &buf, &accumulator);

  size = RSTRING_LEN(buf);
  pbuf = (char *)RSTRING_PTR(buf);

  for (index=0; index<size; index++) {
    index2      = (accumulator>>8)^pbuf[index];
    accumulator = (accumulator<<8)^crc_table[ index2 ];
  }

  return mrb_fixnum_value((uint16_t)accumulator);
}

static mrb_value
mrb_pinpad_s__dukpt_encrypt_buffer(mrb_state *mrb, mrb_value klass)
{
  /*mrb_int ret, slot=0;*/
  /*unsigned char output[1024]={0x00};*/
  /*unsigned char abKSN[1024]={0x00};*/
  /*mrb_value message, array;*/
  mrb_value array;
  /*GEDI_KMS_st_Data pstData;*/

  /*memset(&pstData, 0, sizeof(pstData));*/

  /*mrb_get_args(mrb, "iS", &slot, &message);*/

  /*pstData.bVersion    = 0;*/
  /*pstData.eOperation  = 0;*/
  /*pstData.eKeyType    = 3;*/
  /*pstData.uiKeyIndex  = slot;*/
  /*pstData.eMode       = 24; // GEDI_KMS_ENCMODE_ECB_3DUKPT_P3*/
  /*pstData.abInput     = (BYTE *)RSTRING_PTR(message);*/
  /*pstData.uiInputLen  = 8;*/
  /*pstData.abOutput    = (BYTE *)&output;*/
  /*pstData.uiOutputLen = 8;*/
  /*pstData.abKSN       = (BYTE *)&abKSN;*/

  /*ret = GEDI_KMS_EncryptData (&pstData);*/
  /*DUKPT*/
  /*ContextLog(mrb, 0, "RET [%d][%s]", ret, abKSN);*/

  array  = mrb_ary_new(mrb);
  /*mrb_ary_push(mrb, array, mrb_fixnum_value(ret));*/
  /*if (ret == GEDI_RET_OK) {*/
    /*mrb_ary_push(mrb, array, mrb_str_new(mrb, (char *)&output, 8));*/
    /*mrb_ary_push(mrb, array, mrb_str_new(mrb, (char *)&abKSN, 10));*/
  /*}*/

  return array;
}

void
mrb_crypto_init(mrb_state* mrb)
{
  struct RClass *platform, *crypto;

  create_crc_table();

  platform = mrb_class_get(mrb, "Platform");
  crypto   = mrb_define_class_under(mrb, platform, "Crypto", mrb->object_class);

  mrb_define_class_method(mrb , crypto , "crc16" , mrb_s_crc16 , MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb , crypto , "_dukpt_encrypt_buffer" , mrb_pinpad_s__dukpt_encrypt_buffer , MRB_ARGS_REQ(2));
}
