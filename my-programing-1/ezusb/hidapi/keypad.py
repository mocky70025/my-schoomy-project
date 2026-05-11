#!/usr/bin/python3
# apk add py3-hidapi # apt install python3-hid # pacman -S python-hidapi
# python3 -m pip install hidapi --break-system-packages
import hid

h = hid.device()
h.open(0xf055, 0x0002) # VendorID, ProductID
# print("Manufacturer: %s" % h.get_manufacturer_string())
# print("Product: %s" % h.get_product_string())
print("press 4x4 keypad...") # h.set_nonblocking(1)

while True:
  d = h.read(8)
  print(d) # [m, 0, k, 0, 0, 0, 0, 0]
  if d[0] == 130:
    break; # close if press '*' and '#'

print("Closing the usb device")
h.close()
