#!/usr/bin/perl -w
my $i = 0;
printf("const unsigned char %s[] = {\n", $ARGV[0]);
foreach my $x (split //, join "",<STDIN>) {
	printf("0x%02x,", ord($x));
	if (++$i % 16 == 0) { printf "\n"; }
}
printf("};\n");
