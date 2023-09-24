#include "mem_qemu_virt.h"
.section .text.entry, "ax", %progbits      #定义了一个文本段，称为entry
.globl _start

_start:
    lui t0, %hi(root_pte)


    /* setup stack */
    la    sp, stack           # setup stack pointer
    call main                     # 将栈指针(sp)设置为stack_top的地址

.section .bss.stack                 #定义一个称为stack的数据段
.align 12                           #对齐指令，它确保stack_top的地址在内存中按照2^12（4096）字节对齐
.global stack                   #将标签全局化

stack:
    .space KERNAL_STACKSIZE                    #将stack_top标签标记为全局可见的。
    .global stack_top

stack_top:

.section .data
    .align 12
    .global root_pte

root_pte:
    .zero 8*511
    .quad (0x80000 << 10) | 0xcf