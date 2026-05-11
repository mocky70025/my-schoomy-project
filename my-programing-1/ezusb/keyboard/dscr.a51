.module DSCR
.area DSCR_AREA (CODE,ABS)
.org 0x3E00

.globl _DeviceDscr
.globl _ConfigDscr
.globl _ReportDscr
.globl _ReportDscrSize
.globl _str0, _str1, _str2

.even
_DeviceDscr:
  .db 0x12       ; bLength (_DeviceDscrEnd-_DeviceDscr)
  .db 0x01       ; bDescriptorType (DEVICE=1)
  .dw 0x1001     ; bcdUSB (USB spec version=1.10)
  .db 0x00       ; bDeviceClass
  .db 0x00       ; bDeviceSubClass
  .db 0x00       ; bDeviceProtocol
  .db 0x40       ; bMaxPacketSize (64 byte)
  .dw 0x55F0     ; idVendor (f055.io)
  .dw 0x0200     ; idProduct (private prototyping)
  .dw 0x2301     ; bcdDevice (product version=1.23)
  .db 0x01       ; iManufacturer
  .db 0x02       ; iProduct
  .db 0x00       ; iSerialNumber
  .db 0x01       ; bNumConfigurations
_DeviceDscrEnd:

.even
_ConfigDscr:
  .db 9          ; bLength
  .db 0x02       ; bDescriptorType (CONFIG=2)
  .db 9+9+9+7    ; wTotalLength (LSB)
  .db 0x00       ; wTotalLength (MSB)
  .db 0x01       ; bNumInterface
  .db 0x01       ; bConfigurationValue
  .db 0x00       ; iConfiguration
  .db 0x80       ; bmAttributes
  .db 0x32       ; bMaxPower
_InterfaceDscr:
  .db 9          ; bLength
  .db 0x04       ; bDescriptorType (INTERFACE=4)
  .db 0x00       ; bInterfaceNumber
  .db 0x00       ; bAlternateSetting
  .db 0x01       ; bNumEndpoints
  .db 0x03       ; bInterfaceClass
  .db 0x01       ; bInterfaceSubClass
  .db 0x01       ; bInterfaceProtocol (Keyboad=0x01)
  .db 0x00       ; iInterface
_HIDClassDscr:
  .db 9          ; bLength
  .db 0x21       ; bDescriptorType (HIDClass=0x21)
  .dw 0x1001     ; bcdHID (>1.10)
  .db 0x00       ; bCountryCode
  .db 0x01       ; bNumDescriptors
  .db 0x22       ; bDescriptorType (ReportDescriptor=0x22)
_ReportDscrSize:
  .db _ReportDscrEnd-_ReportDscr ; wDescriptorLength (LSB)
  .db 0x00       ; wDescriptorLength (MSB)
_EndpointDscr:
  .db 7          ; bLength
  .db 0x05       ; bDescriptorType (ENDPOINT=5)
  .db 0x81       ; bEndpointAddress (IN, EP1)
  .db 0x03       ; Interrupt Transfer
  .db 0x40       ; wMaxPacketSize (LSB)
  .db 0x00       ; wMaxPacketSize (MSB)
  .db 0x01       ; bInterval
_ConfigDscrEnd:

_ReportDscr:
  .db 0x05, 0x01 ; USAGE_PAGE (Generic Desktop)
  .db 0x09, 0x06 ; USAGE (Keyboard)
  .db 0xa1, 0x01 ; COLLECTION (Application)
  .db 0x05, 0x07 ;   USAGE_PAGE (Keyboard)
  .db 0x19, 0xe0 ;   USAGE_MINIMUM (Keyboard LeftControl)
  .db 0x29, 0xe7 ;   USAGE_MAXIMUM (Keyboard Right GUI)
  .db 0x15, 0x00 ;   LOGICAL_MINIMUM (0)
  .db 0x25, 0x01 ;   LOGICAL_MAXIMUM (1)
  .db 0x75, 0x01 ;   REPORT_SIZE (1)
  .db 0x95, 0x08 ;   REPORT_COUNT (8)
  .db 0x81, 0x02 ;   INPUT (Data,Var,Abs)
  .db 0x95, 0x01 ;   REPORT_COUNT (1)
  .db 0x75, 0x08 ;   REPORT_SIZE (8)
  .db 0x81, 0x03 ;   INPUT (Cnst,Var,Abs)
  .db 0x95, 0x05 ;   REPORT_COUNT (5)
  .db 0x75, 0x01 ;   REPORT_SIZE (1)
  .db 0x05, 0x08 ;   USAGE_PAGE (LEDs)
  .db 0x19, 0x01 ;   USAGE_MINIMUM (Num Lock)
  .db 0x29, 0x05 ;   USAGE_MAXIMUM (Kana)
  .db 0x91, 0x02 ;   OUTPUT (Data,Var,Abs)
  .db 0x95, 0x01 ;   REPORT_COUNT (1)
  .db 0x75, 0x03 ;   REPORT_SIZE (3)
  .db 0x91, 0x03 ;   OUTPUT (Cnst,Var,Abs)
  .db 0x95, 0x06 ;   REPORT_COUNT (6)
  .db 0x75, 0x08 ;   REPORT_SIZE (8)
  .db 0x15, 0x00 ;   LOGICAL_MINIMUM (0)
  .db 0x25, 0x65 ;   LOGICAL_MAXIMUM (101)
  .db 0x05, 0x07 ;   USAGE_PAGE (Keyboard)
  .db 0x19, 0x00 ;   USAGE_MINIMUM (Reserved (no event indicated))
  .db 0x29, 0x65 ;   USAGE_MAXIMUM (Keyboard Application)
  .db 0x81, 0x00 ;   INPUT (Data,Ary,Abs)
  .db 0xc0       ; END_COLLECTION
_ReportDscrEnd:

.even
_str0:
  .db 0x04   ; bLength
  .db 0x03   ; bDescriptorType (STRING=3)
  .dw 0x0904 ; wLangID (ENGLISH=0904)
_str0end:

.even
_str1:
  .db _str1end-_str1 ; bLength
  .db 0x03   ; bDescriptorType (STRING=3)
  .db 'S', 0
  .db 'e', 0
  .db 'c', 0
  .db 'C', 0
  .db 'a', 0
  .db 'm', 0
  .db 'p', 0
_str1end:

.even
_str2:
  .db _str2end-_str2 ; bLength
  .db 0x03   ; bDescriptorType (STRING=3)
  .db 'E', 0
  .db 'Z', 0
  .db '-', 0
  .db 'K', 0
  .db 'e', 0
  .db 'y', 0
  .db 'b', 0
  .db 'o', 0
  .db 'a', 0
  .db 'r', 0
  .db 'd', 0
_str2end:

_UserDscr:
  .dw 0x0000
