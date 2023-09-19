KERNEL = kernel/hello.elf

FW_JUMP = kernel/fw_jump.elf

HOST_CC = gcc
CROSS_COMPILE = riscv64-unknown-elf-
CC 		= $(CROSS_COMPILE)gcc
LD 		= $(CROSS_COMPILE)ld
AR 		= $(CROSS_COMPILE)ar
OBJDUMP = $(CROSS_COMPILE)objdump
GDB     = $(CROSS_COMPILE)gdb

INC_KERNEL = -Iuart  -Iinclude -Iutils -Iexception/include -Itime

CSRCS = $(wildcard uart/*.c) $(wildcard *.s) $(wildcard *.c) $(wildcard utils/*.c) $(wildcard exception/*.S) $(wildcard exception/*.c) $(wildcard time/*.c)
 
CFLAGS = -g -O0 -fno-builtin -nostdlib -mcmodel=medany -Wall -ffreestanding -march=rv64izicsr

CFLAGS_KERNEL=$(INC_KERNEL) $(CFLAGS)

.PHONY: clean

QEMU = qemu-system-riscv64
QEMU_OPTS  = -machine virt
QEMU_OPTS += -kernel $(KERNEL)
QEMU_OPTS += -bios $(FW_JUMP)
QEMU_OPTS += -m 128M
QEMU_OPTS += -nographic
QEMU_OPTS += -smp 2
QEMU_OPTS += -drive file=sdcard.img,if=none,format=raw,id=x0
QEMU_OPTS += -device virtio-blk-device,drive=x0,bus=virtio-mmio-bus.0
QEMU_OPTS += -initrd initrd.img


all: $(KERNEL)

$(KERNEL): $(CSRCS) link.ld
	$(CC) -o $(KERNEL) $(CSRCS) $(CFLAGS_KERNEL) -Tlink.ld

run:  kernel/hello.elf
	$(QEMU) $(QEMU_OPTS)

test: kernel/hello.elf
	$(QEMU) $(QEMU_OPTS) -s -S

gdb:  kernel/hello.elf
	riscv64-unknown-elf-gdb $(KERNEL)

clean: 
	rm -f *.o
 









