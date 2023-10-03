#include "sbi.h"
#include "string.h"
#include "stdio.h"
#include "time.h"
#include "trap_init.h"
#include <stdlib.h>
#include "easy_mem.h"




void main()
{
    printf("hello world\n");

    //暂且就用这样简单的分配吧
    easy_init_mem();

    //初始化了stvec和sscratch寄存器
    trap_init();
    //设置了SIE寄存器和时钟周期
    clock_init();
    //设置了sstatus寄存器
    trap_enable();



}