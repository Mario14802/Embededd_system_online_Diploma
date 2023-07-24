#prepared by Mario Atef (learn in depth)
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
incs=-I .
LIBS=
SRC = $(wildcard *.c) #wildcard must be all small
OBJ = $(SRC:%.c=%.o)
As  = $(wildcard *.s)
AsOBJ = $(As:%.s=%.o)
project_name = learn-in-depth
all: $(project_name).bin
	@echo "all is done"

%.o: %.s
		$(CC)as.exe $(CFLAGS) $< -o $@ 2> log   #$< =dependices ,$@ =target 

%.o: %.c
		$(CC)gcc.exe $(CFLAGS) $(incs) -c $< -o $@

$(project_name).elf: $(OBJ) $(AsOBJ)
		$(CC)ld.exe -T linker-script.ld  $(LIBS)  $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.Map
		cp $(project_name).elf $(project_name).axf

$(project_name).bin: $(project_name).elf
		$(CC)objcopy.exe -O binary $<  $@

clean-all:
	rm  *.o *.elf *.bin *.axf
	@echo "Everything clean"

clean:
	rm *.elf *.bin
