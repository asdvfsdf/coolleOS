#include "time.h"
#include "string.h"
#include "stdio.h"

volatile size_t tictok = 0;

void clock_set_next_event(){
    sbi_set_timer(get_time() + timebase);
}

void clock_init(){

    set_sie_bit_1(SIE_STIE);

    clock_set_next_event();

    tictok = 0;

    printf("set timer interrupts\n");
}
