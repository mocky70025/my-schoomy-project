typedef unsigned char BYTE;
typedef unsigned short WORD;

#include "../for_vscode.h"
__sfr__at(0xB2, OEA);
__sfr__at(0x80, IOA);
__sbit__at(0x80+0, PA0);
__sbit__at(0x80+1, PA1);
__xdata__at(0xE600, CPUCS);
__xdata__at(0xE678, I2CS);
__xdata__at(0xE679, I2DAT);
__xdata__at(0xE67A, I2CTL);

// C0 Boot Load, VID=0x1D50 PID=0x608C [sigrok FX2 LA (8ch)]
BYTE header[] = {0xC0, 0x50, 0x1D, 0x8C, 0x60, 0x00, 0x00, 0x00};

void write_eeprom(BYTE chip, WORD addr, BYTE *data, WORD len)
{
  while (I2CS & 0x40);    // wait for stop to be done
  I2CS = 0x80;            // set start condition
  I2DAT = chip;           // write control byte
  while (!(I2CS & 0x01)); // wait for done
  I2DAT = addr>>8;        // write hight address
  while (!(I2CS & 0x01)); // wait for done
  I2DAT = addr;           // write low address
  while (!(I2CS & 0x01)); // wait for done
  for (BYTE i = 0; i < len; i++) { // max 64 byte/page
    I2DAT = data[i];        // write data
    while (!(I2CS & 0x01)); // wait for done
  }
  I2CS = 0x40; // set stop bit
  // lazy writing to eeprom (add delay)
}

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

WORD write_eeprom_with_verify(BYTE chip, WORD addr, BYTE *data, WORD len)
{
  PA0 = 1;
  for (WORD p = 0; p < len; p += 64) {
    WORD max = (len - p <= 64) ? len - p : 64;
    write_eeprom(chip, addr + p, data + p, max);
    for (long i = 0; i < 300000; i++);
    PA0 = 1 - PA0;
  }
  WORD n = 0;
  PA0 = 0;
  PA1 = 1;
  for (WORD i = 0; i < len; i++) {
    BYTE x = read_eeprom(chip, addr + i);
    if (x == data[i]) n++;
    PA1 = 1 - PA1;
  }
  return n;
}

void main(void)
{
  CPUCS = 0x10; // (b4=1,b3=0:48MHz)
  I2CTL = 0; // STOPIE=0, 400KHZ=0 (i2c bus speed 100kHz)

  OEA = 3; // out:PA0,PA1
  PA0 = 0; // D1:LED on
  PA1 = 0; // D2:LED on

  WORD ok = write_eeprom_with_verify(0xA2, 0x0000, header, sizeof(header));

  if (ok == sizeof(header)) {
    PA0 = 0; // D1:LED on
    PA1 = 1; // D2:LED off
    for (;;);
  }
  for (;;) { // on error (blink LED)
    PA0 = 1 - PA0;
    PA1 = 1 - PA0;
    for (long i = 0; i < 30000; i++);
  }
}
