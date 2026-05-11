#!/usr/bin/python3
# apk add py3-hidapi # apt install python3-hid # pacman -S python-hidapi
# python3 -m pip install hidapi --break-system-packages
import hid
for d in hid.enumerate(0, 0):
  # keys = d.keys()
  p = d['path'].decode().split(':')
  print('Bus %04s Device %04s: ' % (p[0], p[1]), end='')
  print('ID %04x:%04x ' % (d['vendor_id'], d['product_id']), end='')
  print(d['manufacturer_string']+' '+d['product_string'], end='')
  print('')
