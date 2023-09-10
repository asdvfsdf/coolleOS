    .section .text.entry      #定义了一个文本段，称为entry
    .globl _start

_start:
    /* setup stack */
    la    sp, stack_top           # setup stack pointer
    call main                     # 将栈指针(sp)设置为stack_top的地址

    .section .bss.stack                 #定义一个称为stack的数据段
    .align 12                           #对齐指令，它确保stack_top的地址在内存中按照2^12（4096）字节对齐
    .global stack_top                   #将标签全局化

stack_top:
    .space 4096 * 4                     #将stack_top标签标记为全局可见的。
