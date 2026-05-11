CC = sdcc -mmcs51
AS = sdas8051
CYCFX2PROG = cycfx2prog
HEX2BIX = hex2bix
CFLAGS = --opt-code-size --model-small --stack-auto
LFLAGS = --xram-loc 0xe000 --xram-size 0x0200 --iram-size 0x0100
ASFLAGS = -plosgff

TARGET = eeprom

$(TARGET).ihx: $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c -c
	$(CC) $(CFLAGS) $(LFLAGS) $(TARGET).rel -o $(TARGET).ihx

.PHONY:clean run dump
clean:
	rm -f *.asm *.ihx *.iic *.lk *.lst *.map *.mem *.rel *.rst *.sym

run: $(TARGET).ihx
	$(CYCFX2PROG) prg:$(TARGET).ihx run

dump:
	$(CYCFX2PROG) prg:../vend/Vend_Ax.hex run eeprom:0xa9 dram:0,16
