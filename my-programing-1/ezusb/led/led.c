typedef unsigned char BYTE;
typedef unsigned short WORD;

#include "../for_vscode.h"
__sfr__at(0xB2, OEA);
__sfr__at(0x80, IOA);
__sbit__at(0x80+0, PA0);
__sbit__at(0x80+1, PA1);
__xdata__at(0xE600, CPUCS);

void sleep1msec(void)
{
#ifdef __SDCC
  __asm
  mov dptr,#(0xFFFF-(295<<2));
  loop_:
  inc dptr
  mov a,dpl
  orl a,dph
  jnz loop_
  __endasm;
#endif
}

void msleep(WORD msec)
{
  while (msec--) sleep1msec();
}

void main(void)
{
  CPUCS = 0x10; // (b4=1,b3=0:48MHz)
  OEA |= 3; // out:PA0,PA1
  PA0 = 0; // D1 LED is on
  PA1 = 1; // D2 LED is off
  for (;;) {
    PA0 = 1 - PA0;
    PA1 = 1 - PA1;
    msleep(1000);
  }
}
