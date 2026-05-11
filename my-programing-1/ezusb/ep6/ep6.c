#include "../fx2lp.h"

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

static BYTE x1, x2, x3, xA;
static BYTE x4, x5, x6, xB;
static BYTE x7, x8, x9, xC;
static BYTE xK, x0, xS, xD;

void scan4x4(void) {
  PD4 = 0; PD2 = 1; PD0 = 1; PA6 = 1;
  x1 = !PA4;
  x2 = !PA2;
  x3 = !PA0;
  xA = !PB7;
  PD4 = 1; PD2 = 0; PD0 = 1; PA6 = 1;
  x4 = !PA4;
  x5 = !PA2;
  x6 = !PA0;
  xB = !PB7;
  PD4 = 1; PD2 = 1; PD0 = 0; PA6 = 1;
  x7 = !PA4;
  x8 = !PA2;
  x9 = !PA0;
  xC = !PB7;
  PD4 = 1; PD2 = 1; PD0 = 1; PA6 = 0;
  xK = !PA4;
  x0 = !PA2;
  xS = !PA0;
  xD = !PB7;
}

void loop(void) {
  scan4x4();
  EP6FIFOBUF[0] = (x1<<4)*1 | (x2<<0)*2;
  EP6FIFOBUF[1] = (x3<<4)*3 | (xA<<0)*10;
  EP6FIFOBUF[2] = (x4<<4)*4 | (x5<<0)*5;
  EP6FIFOBUF[3] = (x6<<4)*6 | (xB<<0)*11;
  EP6FIFOBUF[4] = (x7<<4)*7 | (x8<<0)*8;
  EP6FIFOBUF[5] = (x9<<4)*9 | (xC<<0)*12;
  EP6FIFOBUF[6] = (xK<<4)*13| (x0<<0)*14;
  EP6FIFOBUF[7] = (xS<<4)*15| (xD<<0)*13;
  EP6BCH = 0;
  EP6BCL = 8;
}

void main(void) {
  CPUCS = b4;     // set CPU clock (b4=1,b3=0:48MHz)
  IFCONFIG |= b6; // set FIFO clock (b6=1:48MHz)

  EP6CFG = 0xE2;  // setup EP6 (1110 0010 TRM p.235 EPxCFG)

  OED = b4|b2|b0; // out:PD4,PD2,PD0
  OEA = b6|b1;    // out:PA6,PA1 (in:PA0,PA2,PA4)
  OEB = 0; // in:PB0-PB7
  PA1 = 1; // D2:LED off

  for(;;) {
    while (EP6CS & b3); // FULL
    loop();
    for (long i = 0; i < 100000; i++); // wait
    PA1 = 1 - PA1;
  }
}
