#include "mem_qemu_virt.h"
    .section .text.entry      #定义了一个文本段，称为entry
    .globl _start

_start:

    li t0, 0xffffffffc0000000-0x80000000
    la t1, root_pte

    #取root_pte高60位
    sub t0, t1, t0
    srli t1, t0, 12

    li t0, (0x8<<60)
    or t2, t0, t1

    csrw satp, t2



    sfence.vma

    /* setup stack */
    la    sp, stack_top           # setup stack pointer
    
    #call main                     # 将栈指针(sp)设置为stack_top的地址
    
    lui t0, %hi(main)
    addi t0, t0, %lo(main)
    jr t0


#    .section .bss.stack                 #定义一个称为stack的数据段
#    .align 12                           #对齐指令，它确保stack_top的地址在内存中按照2^12（4096）字节对齐
#    .global stack_top                   #将标签全局化

.section .data
    .align PAGE_SHIFT
    .global stack

stack:
    .space KERNAL_STACKSIZE
    .global stack_top


stack_top:
                         #将stack_top标签标记为全局可见的。


.section .data
    .align PAGE_SHIFT
    .global root_pte

root_pte:
    .zero 511*8
    .quad (0x80000 << 10) | 0xcf