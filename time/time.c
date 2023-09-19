#include "time.h"
#include "sbi.h"

int tictok = 0;
static uint64_t timebase = 100000;

void set_time(uint64_t time){
    SBI_TIMER(time);
}

uint64_t get_time(){
    return return_time();
}

void clocks_set_next_event(){
    set_time(get_time()+timebase);
}

void init_time(){
    tictok = 0;
    clocks_set_next_event();
}
