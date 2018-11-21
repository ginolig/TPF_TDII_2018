# -----------------------------------------------------------------
# Makefile trabajo final TDII 2018
# -----------------------------------------------------------------

AS = arm-none-eabi-as
LD = arm-none-eabi-ld
CC = arm-none-eabi-gcc

OBJECTS = TPfinal.o delay.o

ASFLAGS = -mcpu=arm7tdmi -g
LDFLAGS = -Ttext=0 -nostartfiles -g
CFLAGS = -Wall -O1 -mcpu=arm7tdmi -g -c

delay.elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o delay.elf

delay.o: delay.s
	$(AS) $(ASFLAGS) delay.s -o delay.o

TPfinal.o: TPfinal.c
	$(CC) $(CFLAGS) TPfinal.c -o TPfinal.o

clean:
	rm *.o *.elf
