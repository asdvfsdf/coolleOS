KERNEL = kernel/hello.elf

FW_JUMP = kernel/fw_jump.elf

HOST_CC = gcc
CROSS_COMPILE = riscv64-unknown-elf-
CC 		= $(CROSS_COMPILE)gcc
LD 		= $(CROSS_COMPILE)ld
AR 		= $(CROSS_COMPILE)ar
OBJDUMP = $(CROSS_COMPILE)objdump
GDB     = $(CROSS_COMPILE)gdb

INC_KERNEL = -Iuart  -Iinclude -Iutils -Iexception/include -Itime -Isbi -Istdio -Istring -Itrap -Imem

CSRCS = $(wildcard uart/*.c) $(wildcard *.S) $(wildcard *.c) \
$(wildcard trap/*.S) $(wildcard trap/*.c) $(wildcard time/*.c) \
$(wildcard sbi/*.c) $(wildcard stdio/*.c) $(wildcard string/*.c) \
$(wildcard mem/*.c)

CFLAGS = -g -O0 -fno-builtin -nostdlib -mcmodel=medany -Wall -ffreestanding -march=rv64imafdzicsr -Tlink.ld

CFLAGS_KERNEL=$(INC_KERNEL) $(CFLAGS)

.PHONY: clean

QEMU = qemu-system-riscv64
QEMU_OPTS  = -machine virt
QEMU_OPTS += -kernel $(KERNEL)
QEMU_OPTS += -bios $(FW_JUMP)
QEMU_OPTS += -m 128M
QEMU_OPTS += -nographic
QEMU_OPTS += -smp 2
#QEMU_OPTS += -drive file=sdcard.img,if=none,format=raw,id=x0
#QEMU_OPTS += -device virtio-blk-device,drive=x0,bus=virtio-mmio-bus.0
#QEMU_OPTS += -initrd initrd.img

GDB_PORT = 23333

GDB_TARGET = $(KERNEL)

all: $(KERNEL)

$(KERNEL): $(CSRCS)
	$(CC) -o $(KERNEL) $(CSRCS) $(CFLAGS_KERNEL)

run:  $(KERNEL) $(FW_JUMP)
	$(QEMU) $(QEMU_OPTS)

.gdbinit:FORCE
	@echo "target remote localhost:$(GDB_PORT)" > .gdbinit
	@echo "symbol-file $(GDB_TARGET)" >> .gdbinit


gdb: $(GDB_TARGET) .gdbinit
	$(QEMU) $(QEMU_OPTS) -gdb tcp::$(GDB_PORT) -S & echo $$! > .qemu_pid
	$(GDB) -iex "add-auto-load-safe-path /home/cola2003/coolleOS/.gdbinit" $(GDB_TARGET) || true
	@kill -9 `cat .qemu_pid` >/dev/null 2>&1 || true
	@rm -f .qemu_pid

push: 
	git add .
	git commit -m $(mes)
	ggit push

clean: 
	rm -f kernel/hello.elf

FORCE:
.PHONY: FORCE

 









