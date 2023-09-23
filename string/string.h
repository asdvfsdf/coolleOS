#ifndef __STRING_H__
#define __STRING_H__

#include "sbi.h"
#include "stdint.h"


#ifndef NULL
#define NULL ((void *)0)
#endif


int strlen(const char *str);
//char *strcpy(char* dest, const char *src);


#endif