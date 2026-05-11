                                      1 .module DSCR
                                      2 .area DSCR_AREA (CODE,ABS)
      003E00                          3 .org 0x3E00
                                      4 
                                      5 .globl _DeviceDscr
                                      6 .globl _ConfigDscr
                                      7 .globl _ReportDscr_Mouse
                                      8 .globl _ReportDscrSize_Mouse
                                      9 .globl _ReportDscr_Keyboard
                                     10 .globl _ReportDscrSize_Keyboard
                                     11 .globl _str0, _str1, _str2
                                     12 
      003E00                         13 .even
      003E00                         14 _DeviceDscr:
      003E00 12                      15   .db _DeviceDscrEnd-_DeviceDscr; bLength
      003E01 01                      16   .db 0x01       ; bDescriptorType (DEVICE=1)
      003E02 10 01                   17   .dw 0x1001     ; bcdUSB (USB spec version)
      003E04 00                      18   .db 0x00       ; bDeviceClass
      003E05 00                      19   .db 0x00       ; bDeviceSubClass
      003E06 00                      20   .db 0x00       ; bDeviceProtocol
      003E07 40                      21   .db 0x40       ; bMaxPacketSize (64 byte)
      003E08 55 F0                   22   .dw 0x55F0     ; idVendor (f055.io)
      003E0A 04 00                   23   .dw 0x0400     ; idProduct (private prototyping)
      003E0C 23 01                   24   .dw 0x2301     ; bcdDevice (product version=1.23)
      003E0E 01                      25   .db 0x01       ; iManufacturer
      003E0F 02                      26   .db 0x02       ; iProduct
      003E10 00                      27   .db 0x00       ; iSerialNumber
      003E11 01                      28   .db 0x01       ; bNumConfigurations
      003E12                         29 _DeviceDscrEnd:
                                     30 
      003E12                         31 .even
      003E12                         32 _ConfigDscr:
      003E12 09                      33   .db 9          ; bLength
      003E13 02                      34   .db 0x02       ; bDescriptorType (CONFIG=2)
      003E14 3B                      35   .db (_ConfigDscrEnd-_ConfigDscr)&0xFF; wTotalLength (LSB)
      003E15 00                      36   .db (_ConfigDscrEnd-_ConfigDscr) >> 8; wTotalLength (MSB)
      003E16 02                      37   .db 0x02       ; bNumInterface (mouse+keyboard=2)
      003E17 01                      38   .db 0x01       ; bConfigurationValue
      003E18 00                      39   .db 0x00       ; iConfiguration
      003E19 80                      40   .db 0x80       ; bmAttributes
      003E1A 32                      41   .db 0x32       ; bMaxPower
      003E1B                         42 _InterfaceDscr_Mouse:
      003E1B 09                      43   .db 9          ; bLength
      003E1C 04                      44   .db 0x04       ; bDescriptorType (INTERFACE=4)
      003E1D 00                      45   .db 0x00       ; bInterfaceNumber
      003E1E 00                      46   .db 0x00       ; bAlternateSetting
      003E1F 01                      47   .db 0x01       ; bNumEndpoints
      003E20 03                      48   .db 0x03       ; bInterfaceClass
      003E21 01                      49   .db 0x01       ; bInterfaceSubClass
      003E22 02                      50   .db 0x02       ; bInterfaceProtocol (Mouse=0x02)
      003E23 00                      51   .db 0x00       ; iInterface
      003E24                         52 _HIDClassDscr_Mouse:
      003E24 09                      53   .db 9          ; bLength
      003E25 21                      54   .db 0x21       ; bDescriptorType (HIDClass=0x21)
      003E26 10 01                   55   .dw 0x1001     ; bcdHID (>1.10)
      003E28 00                      56   .db 0x00       ; bCountryCode
      003E29 01                      57   .db 0x01       ; bNumDescriptors
      003E2A 22                      58   .db 0x22       ; bDescriptorType (ReportDescriptor=0x22)
      003E2B                         59 _ReportDscrSize_Mouse:
      003E2B 32                      60   .db _ReportDscrEnd_Mouse-_ReportDscr_Mouse ; wDescriptorLength (LSB)
      003E2C 00                      61   .db 0x00       ; wDescriptorLength (MSB)
      003E2D                         62 _EndpointDscr_Mouse:
      003E2D 07                      63   .db 7          ; bLength
      003E2E 05                      64   .db 0x05       ; bDescriptorType (ENDPOINT=5)
      003E2F 82                      65   .db 0x82       ; bEndpointAddress (IN, EP2)
      003E30 03                      66   .db 0x03       ; Interrupt Transfer
      003E31 40                      67   .db 0x40       ; wMaxPacketSize (LSB)
      003E32 00                      68   .db 0x00       ; wMaxPacketSize (MSB)
      003E33 01                      69   .db 0x01       ; bInterval
      003E34                         70 _InterfaceDscr_Keyboard:
      003E34 09                      71   .db 9          ; bLength
      003E35 04                      72   .db 0x04       ; bDescriptorType (INTERFACE=4)
      003E36 01                      73   .db 0x01       ; bInterfaceNumber (+1)
      003E37 00                      74   .db 0x00       ; bAlternateSetting
      003E38 01                      75   .db 0x01       ; bNumEndpoints
      003E39 03                      76   .db 0x03       ; bInterfaceClass
      003E3A 01                      77   .db 0x01       ; bInterfaceSubClass
      003E3B 01                      78   .db 0x01       ; bInterfaceProtocol (Keyboad=0x01)
      003E3C 00                      79   .db 0x00       ; iInterface
      003E3D                         80 _HIDClassDscr_Keyboard:
      003E3D 09                      81   .db 9          ; bLength
      003E3E 21                      82   .db 0x21       ; bDescriptorType (HIDClass=0x21)
      003E3F 10 01                   83   .dw 0x1001     ; bcdHID (>1.10)
      003E41 00                      84   .db 0x00       ; bCountryCode
      003E42 01                      85   .db 0x01       ; bNumDescriptors
      003E43 22                      86   .db 0x22       ; bDescriptorType (ReportDescriptor=0x22)
      003E44                         87 _ReportDscrSize_Keyboard:
      003E44 3F                      88   .db _ReportDscrEnd_Keyboard-_ReportDscr_Keyboard ; wDescriptorLength (LSB)
      003E45 00                      89   .db 0x00       ; wDescriptorLength (MSB)
      003E46                         90 _EndpointDscr_Keyboard:
      003E46 07                      91   .db 7          ; bLength
      003E47 05                      92   .db 0x05       ; bDescriptorType (ENDPOINT=5)
      003E48 81                      93   .db 0x81       ; bEndpointAddress (IN, EP1)
      003E49 03                      94   .db 0x03       ; Interrupt Transfer
      003E4A 40                      95   .db 0x40       ; wMaxPacketSize (LSB)
      003E4B 00                      96   .db 0x00       ; wMaxPacketSize (MSB)
      003E4C 01                      97   .db 0x01       ; bInterval
      003E4D                         98 _ConfigDscrEnd:
                                     99 
      003E4E                        100 .even
      003E4E                        101 _ReportDscr_Mouse:
      003E4E 05 01                  102   .db 0x05, 0x01 ; USAGE_PAGE (Generic Desktop)
      003E50 09 02                  103   .db 0x09, 0x02 ; USAGE (Mouse)
      003E52 A1 01                  104   .db 0xa1, 0x01 ; COLLECTION (Application)
      003E54 09 01                  105   .db 0x09, 0x01 ;   USAGE (Pointer)
      003E56 A1 00                  106   .db 0xa1, 0x00 ;   COLLECTION (Physical)
      003E58 05 09                  107   .db 0x05, 0x09 ;     USAGE_PAGE (Button)
      003E5A 19 01                  108   .db 0x19, 0x01 ;     USAGE_MINIMUM (Button 1)
      003E5C 29 03                  109   .db 0x29, 0x03 ;     USAGE_MAXIMUM (Button 3)
      003E5E 15 00                  110   .db 0x15, 0x00 ;     LOGICAL_MINIMUM (0)
      003E60 25 01                  111   .db 0x25, 0x01 ;     LOGICAL_MAXIMUM (1)
      003E62 95 03                  112   .db 0x95, 0x03 ;     REPORT_COUNT (3)
      003E64 75 01                  113   .db 0x75, 0x01 ;     REPORT_SIZE (1)
      003E66 81 02                  114   .db 0x81, 0x02 ;     INPUT (Data,Var,Abs)
      003E68 95 01                  115   .db 0x95, 0x01 ;     REPORT_COUNT (1)
      003E6A 75 05                  116   .db 0x75, 0x05 ;     REPORT_SIZE (5)
      003E6C 81 03                  117   .db 0x81, 0x03 ;     INPUT (Cnst,Var,Abs)
      003E6E 05 01                  118   .db 0x05, 0x01 ;     USAGE_PAGE (Generic Desktop)
      003E70 09 30                  119   .db 0x09, 0x30 ;     USAGE (X)
      003E72 09 31                  120   .db 0x09, 0x31 ;     USAGE (Y)
      003E74 15 81                  121   .db 0x15, 0x81 ;     LOGICAL_MINIMUM (-127)
      003E76 25 7F                  122   .db 0x25, 0x7f ;     LOGICAL_MAXIMUM (127)
      003E78 75 08                  123   .db 0x75, 0x08 ;     REPORT_SIZE (8)
      003E7A 95 02                  124   .db 0x95, 0x02 ;     REPORT_COUNT (2)
      003E7C 81 06                  125   .db 0x81, 0x06 ;     INPUT (Data,Var,Rel)
      003E7E C0                     126   .db 0xc0       ;   END_COLLECTION
      003E7F C0                     127   .db 0xc0       ; END_COLLECTION
      003E80                        128 _ReportDscrEnd_Mouse:
                                    129 
      003E80                        130 .even
      003E80                        131 _ReportDscr_Keyboard:
      003E80 05 01                  132   .db 0x05, 0x01 ; USAGE_PAGE (Generic Desktop)
      003E82 09 06                  133   .db 0x09, 0x06 ; USAGE (Keyboard)
      003E84 A1 01                  134   .db 0xa1, 0x01 ; COLLECTION (Application)
      003E86 05 07                  135   .db 0x05, 0x07 ;   USAGE_PAGE (Keyboard)
      003E88 19 E0                  136   .db 0x19, 0xe0 ;   USAGE_MINIMUM (Keyboard LeftControl)
      003E8A 29 E7                  137   .db 0x29, 0xe7 ;   USAGE_MAXIMUM (Keyboard Right GUI)
      003E8C 15 00                  138   .db 0x15, 0x00 ;   LOGICAL_MINIMUM (0)
      003E8E 25 01                  139   .db 0x25, 0x01 ;   LOGICAL_MAXIMUM (1)
      003E90 75 01                  140   .db 0x75, 0x01 ;   REPORT_SIZE (1)
      003E92 95 08                  141   .db 0x95, 0x08 ;   REPORT_COUNT (8)
      003E94 81 02                  142   .db 0x81, 0x02 ;   INPUT (Data,Var,Abs)
      003E96 95 01                  143   .db 0x95, 0x01 ;   REPORT_COUNT (1)
      003E98 75 08                  144   .db 0x75, 0x08 ;   REPORT_SIZE (8)
      003E9A 81 03                  145   .db 0x81, 0x03 ;   INPUT (Cnst,Var,Abs)
      003E9C 95 05                  146   .db 0x95, 0x05 ;   REPORT_COUNT (5)
      003E9E 75 01                  147   .db 0x75, 0x01 ;   REPORT_SIZE (1)
      003EA0 05 08                  148   .db 0x05, 0x08 ;   USAGE_PAGE (LEDs)
      003EA2 19 01                  149   .db 0x19, 0x01 ;   USAGE_MINIMUM (Num Lock)
      003EA4 29 05                  150   .db 0x29, 0x05 ;   USAGE_MAXIMUM (Kana)
      003EA6 91 02                  151   .db 0x91, 0x02 ;   OUTPUT (Data,Var,Abs)
      003EA8 95 01                  152   .db 0x95, 0x01 ;   REPORT_COUNT (1)
      003EAA 75 03                  153   .db 0x75, 0x03 ;   REPORT_SIZE (3)
      003EAC 91 03                  154   .db 0x91, 0x03 ;   OUTPUT (Cnst,Var,Abs)
      003EAE 95 06                  155   .db 0x95, 0x06 ;   REPORT_COUNT (6)
      003EB0 75 08                  156   .db 0x75, 0x08 ;   REPORT_SIZE (8)
      003EB2 15 00                  157   .db 0x15, 0x00 ;   LOGICAL_MINIMUM (0)
      003EB4 25 65                  158   .db 0x25, 0x65 ;   LOGICAL_MAXIMUM (101)
      003EB6 05 07                  159   .db 0x05, 0x07 ;   USAGE_PAGE (Keyboard)
      003EB8 19 00                  160   .db 0x19, 0x00 ;   USAGE_MINIMUM (Reserved (no event indicated))
      003EBA 29 65                  161   .db 0x29, 0x65 ;   USAGE_MAXIMUM (Keyboard Application)
      003EBC 81 00                  162   .db 0x81, 0x00 ;   INPUT (Data,Ary,Abs)
      003EBE C0                     163   .db 0xc0       ; END_COLLECTION
      003EBF                        164 _ReportDscrEnd_Keyboard:
                                    165 
      003EC0                        166 .even
      003EC0                        167 _str0:
      003EC0 04                     168   .db 0x04   ; bLength
      003EC1 03                     169   .db 0x03   ; bDescriptorType (STRING=3)
      003EC2 09 04                  170   .dw 0x0904 ; wLangID (ENGLISH=0904)
      003EC4                        171 _str0end:
                                    172 
      003EC4                        173 .even
      003EC4                        174 _str1:
      003EC4 10                     175   .db _str1end-_str1 ; bLength
      003EC5 03                     176   .db 0x03   ; bDescriptorType (STRING=3)
      003EC6 53 00                  177   .db 'S', 0
      003EC8 65 00                  178   .db 'e', 0
      003ECA 63 00                  179   .db 'c', 0
      003ECC 43 00                  180   .db 'C', 0
      003ECE 61 00                  181   .db 'a', 0
      003ED0 6D 00                  182   .db 'm', 0
      003ED2 70 00                  183   .db 'p', 0
      003ED4                        184 _str1end:
                                    185 
      003ED4                        186 .even
      003ED4                        187 _str2:
      003ED4 14                     188   .db _str2end-_str2 ; bLength
      003ED5 03                     189   .db 0x03   ; bDescriptorType (STRING=3)
      003ED6 45 00                  190   .db 'E', 0
      003ED8 5A 00                  191   .db 'Z', 0
      003EDA 2D 00                  192   .db '-', 0
      003EDC 42 00                  193   .db 'B', 0
      003EDE 61 00                  194   .db 'a', 0
      003EE0 64 00                  195   .db 'd', 0
      003EE2 55 00                  196   .db 'U', 0
      003EE4 53 00                  197   .db 'S', 0
      003EE6 42 00                  198   .db 'B', 0
      003EE8                        199 _str2end:
                                    200 
      003EE8                        201 _UserDscr:
      003EE8 00 00                  202   .dw 0x0000
