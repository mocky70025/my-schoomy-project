typedef unsigned char BYTE;
#define BIT(n) ((BYTE)1<<(n))

#include "../for_vscode.h"
__sfr__at(0xB2, OEA);
__sfr__at(0x80, IOA);
__sfr__at(0x88, TCON);
__sfr__at(0x89, TMOD);
__sfr__at(0x8A, TL0);
__sfr__at(0x8B, TL1);
__sfr__at(0x8C, TH0);
__sfr__at(0x8D, TH1);
__sfr__at(0x8E, CKCON);
__sfr__at(0xA8, IE);
__xdata__at(0xE600, CPUCS);

void timer0_ISR (void) __interrupt(1) {
    static unsigned int timer0_cnt = 0;
    timer0_cnt++;
    if(timer0_cnt == 5000) { // 0.25sec
        IOA ^= 1; // blink LED
        timer0_cnt = 0;
    }
}

void main(void)
{
    CPUCS = BIT(4); // (b4=1,b3=0:48MHz)
    OEA |= BIT(0) | BIT(1); // out:PA0,PA1
    IOA |= BIT(0); // PA0=1 (D1:LED off)
    IOA &=~BIT(1); // PA1=0 (D2:LED on)

    TMOD = 0x22; // GATE1=0 CxT1=0 mode1=2 Gate0=0 CxT0=0 mode0=2
    CKCON = (CKCON & 0xf8); // timer clock CLKOUT/12 = 4MHz

    TH0 = 256 - 200; // reload value 200 = 20kHz
    TL0 = TH0;

    IE |= BIT(1);   // ET0 = 1 (enable interrupt)
    TCON |= BIT(4); // TR0 = 1 (start timer)
    IE |= BIT(7);   // EA  = 1 (enable global interrupt)

    for(;;);
}
