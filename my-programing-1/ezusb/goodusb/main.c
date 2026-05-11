#include "../fx2lp.h"
extern void isr(void) __interrupt(8);

#define KEYMAP_LANG_IS_JP
#include "keymap.h"

/* ====== util ====== */
void msleep(WORD msec) { while (msec--) for (long i=0; i<8; i++); }

/* 1回だけHIDレポートを送る（必ず release も送る） */
static void send_report(BYTE mod, BYTE keycode) {
  // wait until EP1IN not busy
  while (EP1INCS & b1);

  EP1INBUF[0] = mod;
  EP1INBUF[1] = 0;
  EP1INBUF[2] = keycode;
  EP1INBUF[3] = 0;
  EP1INBUF[4] = 0;
  EP1INBUF[5] = 0;
  EP1INBUF[6] = 0;
  EP1INBUF[7] = 0;
  EP1INBC = 8;

  // wait send done
  while (EP1INCS & b1);

  // release
  EP1INBUF[0] = 0;
  EP1INBUF[1] = 0;
  EP1INBUF[2] = 0;
  EP1INBUF[3] = 0;
  EP1INBUF[4] = 0;
  EP1INBUF[5] = 0;
  EP1INBUF[6] = 0;
  EP1INBUF[7] = 0;
  EP1INBC = 8;

  while (EP1INCS & b1);
}

static void type_char(char c) {
  if (c >= 'a' && c <= 'z') { send_report(0, (BYTE)(KEY_A + (c - 'a'))); return; }
  if (c >= 'A' && c <= 'Z') { send_report(MOD_SHIFT_LEFT, (BYTE)(KEY_A + (c - 'A'))); return; }
  if (c >= '1' && c <= '9') { send_report(0, (BYTE)(KEY_1 + (c - '1'))); return; }
  if (c == '0')             { send_report(0, KEY_0); return; }
  if (c == ' ')             { send_report(0, KEY_SPACE); return; }
  if (c == '-')             { send_report(0, KEY_MINUS); return; }
}

static void type_str(const char *s) {
  while (*s) { type_char(*s++); msleep(10); }
}

/* ====== 4x4 scan (PB7/ABCD は使わない) ======
   行: PD4, PD2, PD0, PA6
   列: PA4, PA2, PA0
   これは教材の ep6 配線に一致。 :contentReference[oaicite:1]{index=1}
*/
static BYTE x1,x2,x3;
static BYTE x4,x5,x6;
static BYTE x7,x8,x9;
static BYTE xK,x0,xS;

static void scan4x4(void) {
  // 列は「入力」として必ずHiにして読む（浮き/押しっぱなし防止）
  PA0 = 1; PA2 = 1; PA4 = 1;

  // row1: PD4=0
  PD4=0; PD2=1; PD0=1; PA6=1;
  x1=!PA4; x2=!PA2; x3=!PA0;

  // row2: PD2=0
  PD4=1; PD2=0; PD0=1; PA6=1;
  x4=!PA4; x5=!PA2; x6=!PA0;

  // row3: PD0=0
  PD4=1; PD2=1; PD0=0; PA6=1;
  x7=!PA4; x8=!PA2; x9=!PA0;

  // row4: PA6=0
  PD4=1; PD2=1; PD0=1; PA6=0;
  xK=!PA4; x0=!PA2; xS=!PA0;
}

/* ====== 暴走を絶対に起こさない制御 ======
   - 押した瞬間だけ 1回 実行
   - 実行後は「全部離す」まで二度と実行しない
*/
static BYTE armed = 1;

static BYTE any_pressed(void) {
  return (x1||x2||x3||x4||x5||x6||x7||x8||x9||xK||x0||xS);
}

static void loop_goodusb(void) {
  scan4x4();

  if (!any_pressed()) { armed = 1; msleep(10); return; }
  if (!armed) { msleep(10); return; }

  msleep(25);
  scan4x4();
  if (!any_pressed()) return;

  armed = 0;
  send_report(0, KEY_A);  // ← 押した瞬間に a を1回だけ
  msleep(150);
}

void main(void) {
  CPUCS = b4;
  IFCONFIG |= b6;

  EP1INCFG  = b7|b5|b4;  // INT IN
  EP1OUTCFG = b7|b5;

  EP2CFG = 0xF2;
  EP4CFG = 0;
  EP6CFG = 0;
  EP8CFG = 0;

  USBIE = b4|b0;
  EIE  |= b0;
  IE   |= b7;

  USBCS = b3|b1;
  SYNCDELAY;
  USBCS &= ~b3;

  // 行=出力、列=入力
  OED = b4|b2|b0;  // PD4,PD2,PD0 out
  OEA = b6|b1;     // PA6,PA1 out (PA0/2/4 in)
  OEB = 0;

  // 列入力を安定化（必須）
  PA0 = 1; PA2 = 1; PA4 = 1;

  msleep(1500);
  for (;;) {
    msleep(1000);
  }
  
}
