#include "../fx2lp.h"

// isr.c
extern void isr(void) __interrupt(8);

#define KEYMAP_LANG_IS_JP
#include "keymap.h"

#define KEYBUF_SIZE 8

BYTE changed_keybuf(void) {
  static BYTE buffer[KEYBUF_SIZE];
  BYTE cnt = 0;
  for (BYTE i = 0; i < KEYBUF_SIZE; i++) {
    if (buffer[i] != EP1INBUF[i]) cnt++;
    buffer[i] = EP1INBUF[i];
  }
  return cnt;
}

void send_key(BYTE k, BYTE m) {
  EP1INBUF[0] = m;
  EP1INBUF[1] = 0;
  EP1INBUF[2] = k;
  EP1INBUF[3] = 0;
  EP1INBUF[4] = 0;
  EP1INBUF[5] = 0;
  EP1INBUF[6] = 0;
  EP1INBUF[7] = 0;
  EP1INBC = KEYBUF_SIZE;
  while (EP1INCS & b1); // BUSY
  EP1INBC = 0;
  while (EP1INCS & b1); // BUSY
}

//      4x4 keypad matrix
// 
// PD4 -- '1'-'2'-'3'-'A'
//         |   |   |   | 
// PD2 -- '4'-'5'-'6'-'B'
//         |   |   |   | 
// PD0 -- '7'-'8'-'9'-'C'
//         |   |   |   | 
// PA6 -- '*'-'0'-'#'-'D'
//         |   |   |   | 
//         |   |   |   | 
//        PA4 PA2 PA0 (-)

void loop(void) {
  BYTE k = 0;
  BYTE m = 0;

  PD4 = 0; PD2 = 1; PD0 = 1; PA6 = 1; // PD4:on
  if (!PA4) k = KEY_1;
  if (!PA2) k = KEY_2;
  if (!PA0) k = KEY_3;
  if (!PB7) k = KEY_A;
  PD4 = 1; PD2 = 0; PD0 = 1; PA6 = 1; // PD2:on
  if (!PA4) k = KEY_4;
  if (!PA2) k = KEY_5;
  if (!PA0) k = KEY_6;
  if (!PB7) k = KEY_B;
  PD4 = 1; PD2 = 1; PD0 = 0; PA6 = 1; // PD0:on
  if (!PA4) k = KEY_7;
  if (!PA2) k = KEY_8;
  if (!PA0) k = KEY_9;
  if (!PB7) k = KEY_C;
  PD4 = 1; PD2 = 1; PD0 = 1; PA6 = 0; // PA6:on
  if (!PA4) m |= MOD_SHIFT_LEFT;
  if (!PA2) k = KEY_0;
  if (!PA0) m |= MOD_GUI_RIGHT;
  if (!PB7) k = KEY_D;

  EP1INBUF[0] = m;
  EP1INBUF[1] = 0;
  EP1INBUF[2] = k;
  EP1INBUF[3] = 0;
  EP1INBUF[4] = 0;
  EP1INBUF[5] = 0;
  EP1INBUF[6] = 0;
  EP1INBUF[7] = 0;

  if (changed_keybuf()) {
    EP1INBC = KEYBUF_SIZE;
    while (EP1INCS & b1);
  }
}

void main(void) {
  CPUCS = b4;     // set CPU clock (b4=1,b3=0:48MHz)
  IFCONFIG |= b6; // set FIFO clock (b6=1:48MHz)

  EP1INCFG  = b7|b5|b4; // setup EP1IN (Interrupt Transfer)
  EP1OUTCFG = b7|b5;    // setup EP1OUT (default:bulk)
  EP2CFG = 0; // disable EP2
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

  for(;;) {
    while (EP1INCS & b1); // BUSY
    loop();
  }
}
