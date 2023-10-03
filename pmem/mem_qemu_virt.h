#ifndef __MEM_QEMU_VIRT_H__
#define __MEM_QEMU_VIRT_H__

#define PAGE_SIZE 4096
#define PAGE_SHIFT 12

//qemu physical memory begin
#define PHYSICAL_MEM_BEGAIN 0x80000000

//physical memory
//128MB
#define PHYSICAL_MEM_END 0x88000000

//128MB-opensbi(0x200000)
#define PHYSICAL_MEM_SIZE 0x7E00000

//0x80000000+opensbi
#define KERNEL_BASE 0x80200000

//from link.ld
extern unsigned int kernel_end;

//0x80000000+opensbi+kernel
#define KERNEL_END &kernel_end


#endif