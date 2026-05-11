#include "../fx2lp.h"

// isr.c
extern void isr(void) __interrupt(8);

#define KEYMAP_LANG_IS_JP
#include "keymap.h"

void msleep(WORD msec)
{
  while (msec--) for (long i = 0; i < 8; i++);
}

void mouse(BYTE b, char x, char y) {
  EP2FIFOBUF[0] = b;
  EP2FIFOBUF[1] = x;
  EP2FIFOBUF[2] = y;
  EP2BCH = 0;
  EP2BCL = 3;
  while (EP2CS & b3); // FULL
}

void key_(BYTE m, BYTE k) {
  EP1INBUF[0] = m;
  EP1INBUF[1] = 0;
  EP1INBUF[2] = k;
  EP1INBUF[3] = 0;
  EP1INBUF[4] = 0;
  EP1INBUF[5] = 0;
  EP1INBUF[6] = 0;
  EP1INBUF[7] = 0;
  EP1INBC = 8;
  while (EP1INCS & b1); // BUSY
}

void key(BYTE m, BYTE k) {
  key_(m, k);
  key_(0, 0);
}

void main(void) {
  CPUCS = b4;     // set CPU clock (b4=1,b3=0:48MHz)
  IFCONFIG |= b6; // set FIFO clock (b6=1:48MHz)

  EP1INCFG  = b7|b5|b4; // setup EP1IN (Interrupt Transfer)
  EP1OUTCFG = b7|b5;    // setup EP1OUT (default:bulk)
  EP2CFG = 0xF2; // setup EP2
  EP4CFG = 0; // disable EP4
  EP6CFG = 0; // disable EP6
  EP8CFG = 0; // disable EP8

  USBIE = b4|b0; // reset IRQ, setup available IRQ
  EIE |= b0;     // enable USB interrupt
  IE |= b7;      // global interrupt enable

  USBCS = b3|b1; // DISCON | RENUM
  SYNCDELAY;
  USBCS &= ~b3; // ~DISCON

  OED = b4|b2|b0; // out:PD4,PD2,PD0
  OEA = b6|b1;    // out:PA6,PA1 (in:PA0,PA2,PA4)
  OEB = 0; // in:PB0-PB7
  PA1 = 1; // D2:LED off

  msleep(500);

  for(;;) {
    key(0, KEY_F);
    key(0, KEY_U);
    key(0, KEY_N);
    key(0, KEY_C);
    key(0, KEY_T);
    key(0, KEY_I);
    key(0, KEY_O);
    key(0, KEY_N);
    key(MOD_SHIFT_LEFT, KEY_8); // (
    key(MOD_SHIFT_LEFT, KEY_9); // )
    key(MOD_SHIFT_LEFT, KEY_LEFTBRACE); // {
    key(MOD_SHIFT_LEFT, KEY_RIGHTBRACE); // }
    for (int i = 1; i < 10; i++) {
      mouse(0, (char)-1, (char)1);
      msleep(5);
    }
    msleep(1000);
  }
}
