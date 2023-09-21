#ifndef __STRING_H__
#define __STRING_H__

#include "sbi.h"
#include "stdint.h"


#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned int size_t;

int strlen(const char *str);


#endif