CC = sdcc -mmcs51
AS = sdas8051
CYCFX2PROG = cycfx2prog
HEX2BIX = hex2bix
CFLAGS = --opt-code-size --model-small --stack-auto
LFLAGS = --xram-loc 0xe000 --xram-size 0x0200 --iram-size 0x0100
ASFLAGS = -plosgff

TARGET = ep6

$(TARGET).ihx: $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c -c
	$(CC) $(CFLAGS) $(LFLAGS) $(TARGET).rel -o $(TARGET).ihx

.PHONY:clean run
clean:
	rm -f *.asm *.ihx *.iic *.lk *.lst *.map *.mem *.rel *.rst *.sym

run: $(TARGET).ihx
	$(CYCFX2PROG) prg:$(TARGET).ihx run dbulk:6,-512,100
