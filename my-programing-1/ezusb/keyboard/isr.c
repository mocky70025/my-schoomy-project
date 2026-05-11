#include "../fx2lp.h"

// dcsr.a51
extern const BYTE DeviceDscr[];
extern const BYTE ConfigDscr[];
extern const BYTE ReportDscr[];
extern const BYTE ReportDscrSize[];
extern const BYTE str0[], str1[], str2[];

const BYTE * const StringDscr[] = {
  str0, str1, str2,
};

void hid_report(const BYTE *addr, const BYTE *size) {
  EP0BCH = 0;
  BYTE n = 0;
  for (BYTE j = 0; j < size[0]; j++) {
    if (n == 64) { // MaxPacketSize
      EP0BCL = n;
      n = 0;
      while (EP0CS & b1); // BUSY
    }
    EP0BUF[n++] = addr[j];
  }
  EP0BCL = n;
}

// interrupt service routine
void isr(void) __interrupt(8) {
  if (USBIRQ & b4) { // URES
      USBIRQ = b4; // clear Usb RESet interrupt request
  }
  if (USBIRQ & b0) { // SETUP
    if (SETUPDAT[1] == 6) { // GET_DESCRIPTOR
      switch (SETUPDAT[3]) {
      case 0x01: // DEVICE
        SUDPTRH = MSB(DeviceDscr);
        SUDPTRL = LSB(DeviceDscr); // &0xFE
        break;
      case 0x02: // CONFIGURATION
        SUDPTRH = MSB(ConfigDscr);
        SUDPTRL = LSB(ConfigDscr); // &0xFE
        break;
      case 0x03: // STRING
        if (SETUPDAT[2] >= sizeof(StringDscr)/sizeof(BYTE*)) {
          EP0CS |= b0; // STALL
          break;
        }
        SUDPTRH = MSB(StringDscr[SETUPDAT[2]]);
        SUDPTRL = LSB(StringDscr[SETUPDAT[2]]); // &0xFE
        break;
      case 0x22: // HID_REPORT
        hid_report(ReportDscr, ReportDscrSize);
        break;
      case 0x06: // DEVICE_QUALIFIER (for USB 2.0 HighSpeed)
        // unimplemented
      case 0x07: // OTHER_SPEED_CONFIGURATION (for USB2.0HS)
        // unimplemented
      default:
        EP0CS |= b0; // STALL
      }
    }
    else if (SETUPDAT[1] == 8) { // GET_CONFIGURATION
      EP0BUF[0] = 1;
      EP0BCH = 0;
      EP0BCL = 1;
    }
    else if (SETUPDAT[1] == 9) { // SET_CONFIGURATION
      static BYTE config;
      config = EP0BUF[2];
    }
    else if (SETUPDAT[1] == 10) { // GET_INTERFACE
    }
    else {
    }
    EP0CS |= b7; // HSNAK (automatically handshake NAKs)
    USBIRQ = b0; // SUDAV (SETUP Data Available)
  }
}
