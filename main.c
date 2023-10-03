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
    
    // trap_init();
    // clock_init();
    // trap_enable();
    
    //暂且就用这样简单的分配吧
    easy_init_mem();


}