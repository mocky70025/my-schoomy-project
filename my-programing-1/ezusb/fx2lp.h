#ifndef FX2LP_H 
#define FX2LP_H

// typedef
typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

// define
#define MSB(w) ((WORD)w>>8)
#define LSB(w) ((WORD)w&0xFF)
#define b0 0x01
#define b1 0x02
#define b2 0x04
#define b3 0x08
#define b4 0x10
#define b5 0x20
#define b6 0x40
#define b7 0x80
#define NOP do{__asm \
  nop\
  __endasm;}while(0)
#define SYNCDELAY do{NOP;NOP;NOP;NOP;}while(0)
#include "for_vscode.h"

/*
 * EZ-USB(R) Technical Reference Manual
 * https://www.cypress.com/file/126446
 * pp.384-394
 * Table C-1. EZ-USB Registers and Buffers
 */

// GPIF Waveform Memories
__xdata__at(0xE400, WAVEDATA);

// GENERAL CONFIGURATION
__xdata__at(0xE600, CPUCS);
__xdata__at(0xE601, IFCONFIG);
__xdata__at(0xE602, PINFLAGSAB);
__xdata__at(0xE603, PINFLAGSCD);
__xdata__at(0xE604, FIFORESET);
__xdata__at(0xE605, BREAKPT);
__xdata__at(0xE606, BPADDRH);
__xdata__at(0xE607, BPADDRL);
__xdata__at(0xE608, UART230);
__xdata__at(0xE609, FIFOPINPOLAR);
__xdata__at(0xE60A, REVID);
__xdata__at(0xE60B, REVCTL);

// UDMA
__xdata__at(0xE60C, GPIFHOLDAMOUNT);

// ENDPOINT CONFIGURATION
__xdata__at(0xE610, EP1OUTCFG);
__xdata__at(0xE611, EP1INCFG);
__xdata__at(0xE612, EP2CFG);
__xdata__at(0xE613, EP4CFG);
__xdata__at(0xE614, EP6CFG);
__xdata__at(0xE615, EP8CFG);
__xdata__at(0xE618, EP2FIFOCFG);
__xdata__at(0xE619, EP4FIFOCFG);
__xdata__at(0xE61A, EP6FIFOCFG);
__xdata__at(0xE61B, EP8FIFOCFG);
__xdata__at(0xE620, EP2AUTOINLENH);
__xdata__at(0xE621, EP2AUTOINLENL);
__xdata__at(0xE622, EP4AUTOINLENH);
__xdata__at(0xE623, EP4AUTOINLENL);
__xdata__at(0xE624, EP6AUTOINLENH);
__xdata__at(0xE625, EP6AUTOINLENL);
__xdata__at(0xE626, EP8AUTOINLENH);
__xdata__at(0xE627, EP8AUTOINLENL);
__xdata__at(0xE628, ECCCFG);
__xdata__at(0xE629, ECCRESET);
__xdata__at(0xE62A, ECC1B0);
__xdata__at(0xE62B, ECC1B1);
__xdata__at(0xE62C, ECC1B2);
__xdata__at(0xE62D, ECC2B0);
__xdata__at(0xE62E, ECC2B1);
__xdata__at(0xE62F, ECC2B2);
__xdata__at(0xE630, EP2FIFOPFH);
__xdata__at(0xE631, EP2FIFOPFL);
__xdata__at(0xE632, EP4FIFOPFH);
__xdata__at(0xE633, EP4FIFOPFL);
__xdata__at(0xE634, EP6FIFOPFH);
__xdata__at(0xE635, EP6FIFOPFL);
__xdata__at(0xE636, EP8FIFOPFH);
__xdata__at(0xE637, EP8FIFOPFL);
__xdata__at(0xE640, EP2ISOINPKTS);
__xdata__at(0xE641, EP4ISOINPKTS);
__xdata__at(0xE642, EP6ISOINPKTS);
__xdata__at(0xE643, EP8ISOINPKTS);
__xdata__at(0xE648, INPKTEND);
__xdata__at(0xE649, OUTPKTEND);

// INTERRUPTS
__xdata__at(0xE650, EP2FIFOIE);
__xdata__at(0xE651, EP2FIFOIRQ);
__xdata__at(0xE652, EP4FIFOIE);
__xdata__at(0xE653, EP4FIFOIRQ);
__xdata__at(0xE654, EP6FIFOIE);
__xdata__at(0xE655, EP6FIFOIRQ);
__xdata__at(0xE656, EP8FIFOIE);
__xdata__at(0xE657, EP8FIFOIRQ);
__xdata__at(0xE658, IBNIE);
__xdata__at(0xE659, IBNIRQ);
__xdata__at(0xE65A, NAKIE);
__xdata__at(0xE65B, NAKIRQ);
__xdata__at(0xE65C, USBIE);
__xdata__at(0xE65D, USBIRQ);
__xdata__at(0xE65E, EPIE);
__xdata__at(0xE65F, EPIRQ);
__xdata__at(0xE660, GPIFIE);
__xdata__at(0xE661, GPIFIRQ);
__xdata__at(0xE662, USBERRIE);
__xdata__at(0xE663, USBERRIRQ);
__xdata__at(0xE664, ERRCNTLIM);
__xdata__at(0xE665, CLRERRCNT);
__xdata__at(0xE666, INT2IVEC);
__xdata__at(0xE667, INT4IVEC);
__xdata__at(0xE668, INTSETUP);

// INPUT/OUTPUT
__xdata__at(0xE670, PORTACFG);
__xdata__at(0xE671, PORTCCFG);
__xdata__at(0xE672, PORTECFG);
__xdata__at(0xE678, I2CS);
__xdata__at(0xE679, I2DAT);
__xdata__at(0xE67A, I2CTL);
__xdata__at(0xE67B, XAUTODAT1);
__xdata__at(0xE67C, XAUTODAT2);

// UDMA CRC
__xdata__at(0xE67D, UDMACRCH);
__xdata__at(0xE67E, UDMACRCL);
__xdata__at(0xE67F, UDMACRCQUAL);

// USB CONTROL
__xdata__at(0xE680, USBCS);
__xdata__at(0xE681, SUSPEND);
__xdata__at(0xE682, WAKEUPCS);
__xdata__at(0xE683, TOGCTL);
__xdata__at(0xE684, USBFRAMEH);
__xdata__at(0xE685, USBFRAMEL);
__xdata__at(0xE686, MICROFRAME);
__xdata__at(0xE687, FNADDR);

// ENDPOINTS
__xdata__at(0xE68A, EP0BCH);
__xdata__at(0xE68B, EP0BCL);
__xdata__at(0xE68D, EP1OUTBC);
__xdata__at(0xE68F, EP1INBC);
__xdata__at(0xE690, EP2BCH);
__xdata__at(0xE691, EP2BCL);
__xdata__at(0xE694, EP4BCH);
__xdata__at(0xE695, EP4BCL);
__xdata__at(0xE698, EP6BCH);
__xdata__at(0xE699, EP6BCL);
__xdata__at(0xE69C, EP8BCH);
__xdata__at(0xE69D, EP8BCL);
__xdata__at(0xE6A0, EP0CS);
__xdata__at(0xE6A1, EP1OUTCS);
__xdata__at(0xE6A2, EP1INCS);
__xdata__at(0xE6A3, EP2CS);
__xdata__at(0xE6A4, EP4CS);
__xdata__at(0xE6A5, EP6CS);
__xdata__at(0xE6A6, EP8CS);
__xdata__at(0xE6A7, EP2FIFOFLGS);
__xdata__at(0xE6A8, EP4FIFOFLGS);
__xdata__at(0xE6A9, EP6FIFOFLGS);
__xdata__at(0xE6AA, EP8FIFOFLGS);
__xdata__at(0xE6AB, EP2FIFOBCH);
__xdata__at(0xE6AC, EP2FIFOBCL);
__xdata__at(0xE6AD, EP4FIFOBCH);
__xdata__at(0xE6AE, EP4FIFOBCL);
__xdata__at(0xE6AF, EP6FIFOBCH);
__xdata__at(0xE6B0, EP6FIFOBCL);
__xdata__at(0xE6B1, EP8FIFOBCH);
__xdata__at(0xE6B2, EP8FIFOBCL);
__xdata__at(0xE6B3, SUDPTRH);
__xdata__at(0xE6B4, SUDPTRL);
__xdata__at(0xE6B5, SUDPTRCTL);
__xdata__at(0xE6B8, SETUPDAT[8]);

// GPIF
__xdata__at(0xE6C0, GPIFWFSELECT);
__xdata__at(0xE6C1, GPIFIDLECS);
__xdata__at(0xE6C2, GPIFIDLECTL);
__xdata__at(0xE6C3, GPIFCTLCFG);
__xdata__at(0xE6C4, GPIFADRH);
__xdata__at(0xE6C5, GPIFADRL);

// FLOWSTATE
__xdata__at(0xE6C6, FLOWSTATE);
__xdata__at(0xE6C7, FLOWLOGIC);
__xdata__at(0xE6C8, FLOWEQ0CTL);
__xdata__at(0xE6C9, FLOWEQ1CTL);
__xdata__at(0xE6CA, FLOWHOLDOFF);
__xdata__at(0xE6CB, FLOWSTB);
__xdata__at(0xE6CC, FLOWSTBEDGE);
__xdata__at(0xE6CD, FLOWSTBHPERIOD);
__xdata__at(0xE6CE, GPIFTCB3);
__xdata__at(0xE6CF, GPIFTCB2);
__xdata__at(0xE6D0, GPIFTCB1);
__xdata__at(0xE6D1, GPIFTCB0);
__xdata__at(0xE6D2, EP2GPIFFLGSEL);
__xdata__at(0xE6D3, EP2GPIFPFSTOP);
__xdata__at(0xE6D4, EP2GPIFTRIG);
__xdata__at(0xE6DA, EP4GPIFFLGSEL);
__xdata__at(0xE6DB, EP4GPIFPFSTOP);
__xdata__at(0xE6DC, EP4GPIFTRIG);
__xdata__at(0xE6E2, EP6GPIFFLGSEL);
__xdata__at(0xE6E3, EP6GPIFPFSTOP);
__xdata__at(0xE6E4, EP6GPIFTRIG);
__xdata__at(0xE6EA, EP8GPIFFLGSEL);
__xdata__at(0xE6EB, EP8GPIFPFSTOP);
__xdata__at(0xE6EC, EP8GPIFTRIG);
__xdata__at(0xE6F0, XGPIFSGLDATH);
__xdata__at(0xE6F1, XGPIFSGLDATLX);
__xdata__at(0xE6F2, XGPIFSGLDATLNOX);
__xdata__at(0xE6F3, GPIFREADYCFG);
__xdata__at(0xE6F4, GPIFREADYSTAT);
__xdata__at(0xE6F5, GPIFABORT);

// ENDPOINT BUFFERS
__xdata__at(0xE740, EP0BUF[64]);
__xdata__at(0xE780, EP1OUTBUF[64]);
__xdata__at(0xE7C0, EP1INBUF[64]);
__xdata__at(0xF000, EP2FIFOBUF[1024]);
__xdata__at(0xF400, EP4FIFOBUF[1024]);
__xdata__at(0xF800, EP6FIFOBUF[1024]);
__xdata__at(0xFC00, EP8FIFOBUF[1024]);

// Special Function Registers (SFRs)
__sfr__at(0x80, IOA);
__sfr__at(0x81, SP);
__sfr__at(0x82, DPL);
__sfr__at(0x83, DPH);
__sfr__at(0x84, DPL1);
__sfr__at(0x85, DPH1);
__sfr__at(0x86, DPS);
__sfr__at(0x87, PCON);
__sfr__at(0x88, TCON);
__sfr__at(0x89, TMOD);
__sfr__at(0x8A, TL0);
__sfr__at(0x8B, TL1);
__sfr__at(0x8C, TH0);
__sfr__at(0x8D, TH1);
__sfr__at(0x8E, CKCON);
__sfr__at(0x90, IOB);
__sfr__at(0x91, EXIF);
__sfr__at(0x92, MPAGE);
__sfr__at(0x98, SCON0);
__sfr__at(0x99, SBUF0);
__sfr__at(0x9A, AUTOPTRH1);
__sfr__at(0x9B, AUTOPTRL1);
__sfr__at(0x9D, AUTOPTRH2);
__sfr__at(0x9E, AUTOPTRL2);
__sfr__at(0xA0, IOC);
__sfr__at(0xA1, INT2CLR);
__sfr__at(0xA2, INT4CLR);
__sfr__at(0xA8, IE);
__sfr__at(0xAA, EP2468STAT);
__sfr__at(0xAB, EP24FIFOFLGS);
__sfr__at(0xAC, EP68FIFOFLGS);
__sfr__at(0xAF, AUTOPTRSETUP);
__sfr__at(0xB0, IOD);
__sfr__at(0xB1, IOE);
__sfr__at(0xB2, OEA);
__sfr__at(0xB3, OEB);
__sfr__at(0xB4, OEC);
__sfr__at(0xB5, OED);
__sfr__at(0xB6, OEE);
__sfr__at(0xB8, IP);
__sfr__at(0xBA, EP01STAT);
__sfr__at(0xBB, GPIFTRIG);
__sfr__at(0xBD, GPIFSGLDATH);
__sfr__at(0xBE, GPIFSGLDATLX);
__sfr__at(0xBF, GPIFSGLDATLNOX);
__sfr__at(0xC0, SCON1);
__sfr__at(0xC1, SBUF1);
__sfr__at(0xC8, T2CON);
__sfr__at(0xCA, RCAP2L);
__sfr__at(0xCB, RCAP2H);
__sfr__at(0xCC, TL2);
__sfr__at(0xCD, TH2);
__sfr__at(0xD0, PSW);
__sfr__at(0xD8, EICON);
__sfr__at(0xE0, ACC);
__sfr__at(0xE8, EIE);
__sfr__at(0xF0, B);
__sfr__at(0xF8, EIP);

// special function bits
__sbit__at(0x80+0, PA0);
__sbit__at(0x80+1, PA1);
__sbit__at(0x80+2, PA2);
__sbit__at(0x80+3, PA3);
__sbit__at(0x80+4, PA4);
__sbit__at(0x80+5, PA5);
__sbit__at(0x80+6, PA6);
__sbit__at(0x80+7, PA7);
__sbit__at(0x88+0, IT0);
__sbit__at(0x88+1, IE0);
__sbit__at(0x88+2, IT1);
__sbit__at(0x88+3, IE1);
__sbit__at(0x88+4, TR0);
__sbit__at(0x88+5, TF0);
__sbit__at(0x88+6, TR1);
__sbit__at(0x88+7, TF1);
__sbit__at(0x90+0, PB0);
__sbit__at(0x90+1, PB1);
__sbit__at(0x90+2, PB2);
__sbit__at(0x90+3, PB3);
__sbit__at(0x90+4, PB4);
__sbit__at(0x90+5, PB5);
__sbit__at(0x90+6, PB6);
__sbit__at(0x90+7, PB7);
__sbit__at(0x98+0, RI);
__sbit__at(0x98+1, TI);
__sbit__at(0x98+2, RB8);
__sbit__at(0x98+3, TB8);
__sbit__at(0x98+4, REN);
__sbit__at(0x98+5, SM2);
__sbit__at(0x98+6, SM1);
__sbit__at(0x98+7, SM0);
__sbit__at(0xA0+0, PC0);
__sbit__at(0xA0+1, PC1);
__sbit__at(0xA0+2, PC2);
__sbit__at(0xA0+3, PC3);
__sbit__at(0xA0+4, PC4);
__sbit__at(0xA0+5, PC5);
__sbit__at(0xA0+6, PC6);
__sbit__at(0xA0+7, PC7);
__sbit__at(0xA8+0, EX0);
__sbit__at(0xA8+1, ET0);
__sbit__at(0xA8+2, EX1);
__sbit__at(0xA8+3, ET1);
__sbit__at(0xA8+4, ES0);
__sbit__at(0xA8+5, ET2);
__sbit__at(0xA8+6, ES1);
__sbit__at(0xA8+7, EA);
__sbit__at(0xB0+0, PD0);
__sbit__at(0xB0+1, PD1);
__sbit__at(0xB0+2, PD2);
__sbit__at(0xB0+3, PD3);
__sbit__at(0xB0+4, PD4);
__sbit__at(0xB0+5, PD5);
__sbit__at(0xB0+6, PD6);
__sbit__at(0xB0+7, PD7);
__sbit__at(0xB8+0, PX0);
__sbit__at(0xB8+1, PT0);
__sbit__at(0xB8+2, PX1);
__sbit__at(0xB8+3, PT1);
__sbit__at(0xB8+4, PS0);
__sbit__at(0xB8+5, PT2);
__sbit__at(0xB8+6, PS1);
__sbit__at(0xC0+0, RI1);
__sbit__at(0xC0+1, TI1);
__sbit__at(0xC0+2, RB81);
__sbit__at(0xC0+3, TB81);
__sbit__at(0xC0+4, REN1);
__sbit__at(0xC0+5, SM21);
__sbit__at(0xC0+6, SM11);
__sbit__at(0xC0+7, SM01);
__sbit__at(0xC8+0, CP_RL2);
__sbit__at(0xC8+1, C_T2);
__sbit__at(0xC8+2, TR2);
__sbit__at(0xC8+3, EXEN2);
__sbit__at(0xC8+4, TCLK);
__sbit__at(0xC8+5, RCLK);
__sbit__at(0xC8+6, EXF2);
__sbit__at(0xC8+7, TF2);
__sbit__at(0xD0+0, P);
__sbit__at(0xD0+1, FL);
__sbit__at(0xD0+2, OV);
__sbit__at(0xD0+3, RS0);
__sbit__at(0xD0+4, RS1);
__sbit__at(0xD0+5, F0);
__sbit__at(0xD0+6, AC);
__sbit__at(0xD0+7, CY);
__sbit__at(0xD8+3, INT6);
__sbit__at(0xD8+4, RESI);
__sbit__at(0xD8+5, ERESI);
__sbit__at(0xD8+7, SMOD1);
__sbit__at(0xE8+0, EUSB);
__sbit__at(0xE8+1, EI2C);
__sbit__at(0xE8+2, EIEX4);
__sbit__at(0xE8+3, EIEX5);
__sbit__at(0xE8+4, EIEX6);
__sbit__at(0xF8+0, PUSB);
__sbit__at(0xF8+1, PI2C);
__sbit__at(0xF8+2, EIPX4);
__sbit__at(0xF8+3, EIPX5);
__sbit__at(0xF8+4, EIPX6);

#endif
