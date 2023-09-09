KERNEL = kernel/hello.elf

FW_JUMP = kernel/fw_jump.elf

HOST_CC = gcc
CROSS_COMPILE = riscv64-unknown-elf-
CC 		= $(CROSS_COMPILE)gcc
LD 		= $(CROSS_COMPILE)ld
AR 		= $(CROSS_COMPILE)ar
OBJDUMP = $(CROSS_COMPILE)objdump
GDB     = $(CROSS_COMPILE)gdb

CSRCS = entry.o main.o

#CFLAGS = 
.PHONY: clean

QEMU = qemu-system-riscv64
QEMU_OPTS  = -machine virt
QEMU_OPTS += -kernel $(KERNEL)
QEMU_OPTS += -bios $(FW_JUMP)
QEMU_OPTS += -m 128M
QEMU_OPTS += -nographic
QEMU_OPTS += -smp 2

all: $(KERNEL_QEMU)

$(KERNEL_QEMU): $(CSRCS)
	$(LD) -o kernel/hello.elf entry.o main.o -Tlink.ld

entry.o: entry.s
	$(CC) -nostdlib -c entry.s -o entry.o

main.o: main.c 
	$(CC) -nostdlib -c main.c -o main.o

run:  kernel/hello.elf
	$(QEMU) $(QEMU_OPTS)

clean: 
	rm -f *.o
 









