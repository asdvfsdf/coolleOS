#ifndef __LOCK_H__
#define __LOCK_H__

#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"

//我的锁头可以简单一点，目前看没必要带那个cpu
 
struct lock
{
    _Bool locked;
    char* name;

};

void init_lock(struct lock* lock,char* name);

void lockit(struct lock* lock);

void unlockit(struct lock* lock);

#endif