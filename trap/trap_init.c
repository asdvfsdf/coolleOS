#include "trap_init.h"

void trap_init(){
    //set stvec 
    const_set_stvec();

    //set sscratch
    set_sscratch(0);
    
    
}
