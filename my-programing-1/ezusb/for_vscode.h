#ifdef __SDCC
#define __sfr__at(a, b)   __sfr __at(a) b
#define __sbit__at(a, b)  __sbit __at(a) b
#define __xdata__at(a, b) __xdata __at(a) volatile BYTE b
#else
// for VS Code
#define __sfr__at(a, b)   volatile BYTE b
#define __sbit__at(a, b)  volatile BYTE b
#define __xdata__at(a, b) volatile BYTE b
#define __interrupt(i)
#define __sfr
#define __sbit
#define __xdata
#undef  NOP
#define NOP
#undef  SYNCDELAY
#define SYNCDELAY
#endif
