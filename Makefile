KERNEL = kernel/hello.elf

FW_JUMP = kernel/fw_jump.elf

HOST_CC = gcc
CROSS_COMPILE = riscv64-unknown-elf-
CC 		= $(CROSS_COMPILE)gcc
LD 		= $(CROSS_COMPILE)ld
AR 		= $(CROSS_COMPILE)ar
OBJDUMP = $(CROSS_COMPILE)objdump
GDB     = $(CROSS_COMPILE)gdb

INC_KERNEL = -Iuart  -Iinclude

CSRCS = $(wildcard uart/*.c) $(wildcard *.s) $(wildcard *.c)
 
CFLAGS = -fno-builtin -nostdlib -nostdinc -Wall

CFLAGS_KERNEL=$(INC_KERNEL) $(CFLAGS)

.PHONY: clean

QEMU = qemu-system-riscv64
QEMU_OPTS  = -machine virt
QEMU_OPTS += -kernel $(KERNEL)
QEMU_OPTS += -bios $(FW_JUMP)
QEMU_OPTS += -m 128M
QEMU_OPTS += -nographic
QEMU_OPTS += -smp 2


all: $(KERNEL)

$(KERNEL): $(CSRCS) link.ld
	$(CC) -o $(KERNEL) $(CSRCS) $(CFLAGS_KERNEL) -Tlink.ld

run:  kernel/hello.elf
	$(QEMU) $(QEMU_OPTS)

clean: 
	rm -f *.o
 









