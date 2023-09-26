#include "mmu.h"


#define KERNAL_STACKPAGE          2                                    //  of pages in kernel stack
#define KERNAL_STACKSIZE          (KERNAL_STACKPAGE * PAGE_SIZE)       // sizeof kernel stack

.section .text.entry, "ax", %progbits      #定义了一个文本段，称为entry
.globl _start

_start:
    /* setup stack */
    la    sp, entry_stack           # setup stack pointer
    call main                     # 将栈指针(sp)设置为stack_top的地址

.section .bss.entry_stack                 #定义一个称为stack的数据段
.align 12                           #对齐指令，它确保stack_top的地址在内存中按照2^12（4096）字节对齐
.global entry_stack                   #将标签全局化

entry_stack:
    .space KERNAL_STACKSIZE                    #将stack_top标签标记为全局可见的。
    .global entry_stack_top

entry_stack_top:
