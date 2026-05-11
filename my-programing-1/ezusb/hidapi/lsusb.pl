#!/usr/bin/perl -w
# apk add perl-usb-libusb
use USB::LibUSB;
use Data::Dumper;

my $ctx = USB::LibUSB->init();
my @devices = $ctx->get_device_list();

for my $dev (@devices) {
  my $bus = $dev->get_bus_number();
  my $address = $dev->get_device_address();
  my $desc = $dev->get_device_descriptor();
  my $idVendor = $desc->{idVendor};
  my $idProduct = $desc->{idProduct};

  printf("Bus %03d Device %03d: ID %04x:%04x\n",
         $bus, $address, $idVendor, $idProduct);
  print Dumper $desc;
}
