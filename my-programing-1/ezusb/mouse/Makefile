CC = sdcc -mmcs51
AS = sdas8051
CYCFX2PROG = cycfx2prog
HEX2BIX = hex2bix
CFLAGS = --opt-code-size --model-small --stack-auto
LFLAGS = --xram-loc 0xe000 --xram-size 0x0200 --iram-size 0x0100
ASFLAGS = -plosgff

TARGET = ez
OBJECT = main.rel isr.rel dscr.rel

$(TARGET).ihx: $(OBJECT)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJECT) -o $(TARGET).ihx

%.rel: %.c
	$(CC) $(CFLAGS) $< -c

%.rel: %.a51
	$(AS) $(ASFLAGS) $@ $<

.PHONY:clean run
clean:
	rm -f *.asm *.ihx *.iic *.lk *.lst *.map *.mem *.rel *.rst *.sym

run: $(TARGET).ihx
	$(CYCFX2PROG) prg:$(TARGET).ihx run
