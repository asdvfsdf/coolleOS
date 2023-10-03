#include "lock.h"

void init_lock(struct lock* lock,char* name){
    
    lock->name = name;
    lock->locked = 0;
}

void lockit(struct lock* lock){
    
    if(lock->locked == 1){
        panic("the lock has been locked\n");
    }else{
        lock->locked = 1;
    }
}

void unlockit(struct lock* lock){
    if(lock->locked == 0){
        panic("the lock has been unlocked\n");
    }else{
        lock->locked = 0;
    }
}