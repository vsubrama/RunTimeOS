SOURCES = $(shell ls *.c)
OBJECTS = $(SOURCES:.c=.o)
ASM_SOURCES = $(shell ls *.x86)
ASM_OBJECTS = $(ASM_SOURCES:.x86=.xo)

BINARY = kernel.img

CC = gcc
CFLAGS = -m32 -Wall -std=c11 -fno-stack-protector -ffreestanding
ASM = nasm
ASM_FLAGS = -f elf32
LD = ld
LDFLAGS = -m elf_i386 -nostdlib -T link.ld

all : $(BINARY) $(SOURCES) $(ASM_SOURCES)

run : $(BINARY)
	qemu-system-i386 -kernel $(BINARY)

clean :
	rm *.o *.xo *.img

$(BINARY) : $(OBJECTS) $(ASM_OBJECTS)
	$(LD) $(LDFLAGS) -o $(BINARY) $(OBJECTS) $(ASM_OBJECTS)

%.xo : %.x86
	$(ASM) $(ASM_FLAGS) -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<
