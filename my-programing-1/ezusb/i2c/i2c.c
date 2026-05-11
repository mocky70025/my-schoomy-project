typedef unsigned char BYTE;
typedef unsigned short WORD;

#include "../for_vscode.h"
__sfr__at(0xB2, OEA);
__sfr__at(0x80, IOA);
__sbit__at(0x80+0, PA0);
__sbit__at(0x80+1, PA1);
__xdata__at(0xE600, CPUCS);
__xdata__at(0xE604, FIFORESET);
__xdata__at(0xE614, EP6CFG);
__xdata__at(0xE678, I2CS);
__xdata__at(0xE679, I2DAT);
__xdata__at(0xE67A, I2CTL);
__xdata__at(0xE698, EP6BCH);
__xdata__at(0xE699, EP6BCL);
__xdata__at(0xF800, EP6FIFOBUF[1024]);

BYTE read_eeprom(BYTE chip, WORD addr)
{
  BYTE dummy;

  while (I2CS & 0x40);    // wait for stop to be done
  I2CS = 0x80;            // set start condition
  I2DAT = chip;           // write control byte
  while (!(I2CS & 0x01)); // wait for done
  I2DAT = addr>>8;        // write hight address
  while (!(I2CS & 0x01)); // wait for done
  I2DAT = addr;           // write low address
  while (!(I2CS & 0x01)); // wait for done

  I2CS = 0x80;            // set start condition
  I2DAT = chip | 0x01;    // write control byte
  while (!(I2CS & 0x01)); // wait for done
  I2CS = 0x20;            // set last read condition
  dummy = I2DAT;          // read the dummy
  while (!(I2CS & 0x01)); // wait for done
  I2CS = 0x40;            // set stop bit
  return I2DAT;           // return data
}

void main(void)
{
  CPUCS = 0x10; // (b4=1,b3=0:48MHz)
  I2CTL = 0; // STOPIE=0, 400KHZ=0 (i2c bus speed 100kHz)
  EP6CFG = 0xE2;  // setup EP6 (1110 0010 TRM p.235 EPxCFG)

  #define chip 0xA2
  #define addr 0x0000
  #define size 16
  for (WORD i = 0; i < size; i++) {
    EP6FIFOBUF[i] = read_eeprom(chip, addr + i);
  }
  EP6BCH = 0;
  EP6BCL = size;
  
  for(;;);
}
