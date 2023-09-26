#include "sbi.h"
#include "string.h"
#include "stdio.h"
#include "time.h"
#include "trap_init.h"
#include <stdlib.h>
#include "mem_qemu_virt.h"


void main()
{
    // trap_init();
    // clock_init();
    // trap_enable();

    printf("hello world\n");
    printf("%x\n",KERNEL_END);

}