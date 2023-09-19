#ifndef __SLICE_H__
#define __SLICE_H__

#include <stdbool.h>
#include "string.h"
#include <stddef.h>

typedef struct  
{
    int *data;
    size_t len;
}slice;

slice creat_slice(int *arr,size_t len);
int get_element(const slice *slice,size_t idx);

#endif


