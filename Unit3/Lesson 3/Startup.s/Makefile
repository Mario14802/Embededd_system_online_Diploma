#prepared by Mario Atef (learn in depth)
CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
incs=-I .
LIBS=
SRC = $(wildcard *.c) #wildcard must be all small
OBJ = $(SRC:%.c=%.o)
As  = $(wildcard *.s)
AsOBJ = $(As:%.s=%.o)

all: learn-in-depth.bin
	@echo "all is done"

%.o: %.s
		$(CC)as.exe $(CFLAGS) $< -o $@ 2> log   #$< =dependices ,$@ =target 

%.o: %.c
		$(CC)gcc.exe $(CFLAGS) $(incs) -c $< -o $@

learn-in-depth.elf: $(OBJ) $(AsOBJ)
		$(CC)ld.exe -T linker_script.ld  $(LIBS)  $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.Map

learn-in-depth.bin: learn-in-depth.elf
		$(CC)objcopy.exe -O binary $<  $@

clean-all:
	rm  *.o *.elf *.bin
	@echo "Everything clean"

clean:
	rm *.elf *.bin
