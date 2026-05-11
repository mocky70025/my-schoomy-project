CC = sdcc -mmcs51
AS = sdas8051
CYCFX2PROG = cycfx2prog
HEX2BIX = ./hex2bix
CFLAGS = --opt-code-size --model-small --stack-auto
LFLAGS = --xram-loc 0xe000 --xram-size 0x0200 --iram-size 0x0100
ASFLAGS = -plosgff

C2_LOAD= -F 0xC2 -V 0x04b4 -P 0x8613 -N 0x0123 -M 0x4000
IHX=../keyboard/ez.ihx

TARGET = eeprom

$(TARGET).ihx: c2load.h $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c -c
	$(CC) $(CFLAGS) $(LFLAGS) $(TARGET).rel -o $(TARGET).ihx

c2load.iic: $(IHX) hex2bix
	$(HEX2BIX) -I $(C2_LOAD) -O c2load.iic $(IHX)

c2load.h: c2load.iic
	perl iic2h.pl c2load < c2load.iic > c2load.h

hex2bix: hex2bix.c
	gcc -w hex2bix.c -o hex2bix
	sleep 0.5

.PHONY:clean run dump
clean:
	rm -f hex2bix *.asm *.ihx *.iic *.lk *.lst *.map *.mem *.rel *.rst *.sym

run: $(TARGET).ihx
	$(CYCFX2PROG) prg:$(TARGET).ihx run
