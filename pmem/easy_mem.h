#ifndef __EASY_MEM_H__
#define __EASY_MEM_H__

#include "stdint.h"

struct easy_page
{   
    //[0]表示是否被占用
    u8 flags;
};

#define ROUNDDOWN(a, n) ({                                          \
            size_t __a = (size_t)(a);                               \
            (typeof(a))(__a - __a % (n));                           \
        })

/* Round up to the nearest multiple of n */
#define ROUNDUP(a, n) ({                                            \
            size_t __n = (size_t)(n);                               \
            (typeof(a))(ROUNDDOWN((size_t)(a) + __n - 1, __n));     \
        })

void easy_init_mem();

u64 easy_alloc(u64 num);


#endif