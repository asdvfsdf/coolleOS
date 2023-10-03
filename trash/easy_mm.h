#ifndef __PMALLOC_H__
#define __PMALLOC_H__

#include "pmem.h"

#define KMEM_OBJ_MIN_SIZE   ((u64)32)
#define KMEM_OBJ_MAX_SIZE 	((u64)4048)
#define KMEM_OBJ_MAX_COUNT  (PHYSICAL_PAGE_SIZE / KMEM_OBJ_MIN_SIZE)

#define sizeof(type) ((size_t) ((type*)0 + 1))

#define ROUNDUP16(n) (((n) + 15) & ~0x0f)

#define PMEM_TABLE_SIZE 17

#define _hash(n) ((n) % PMEM_TABLE_SIZE)

#define ROUNDDOWN(a, n) ({                                          \
            size_t __a = (size_t)(a);                               \
            (typeof(a))(__a - __a % (n));                           \
        })

/* Round up to the nearest multiple of n */
#define ROUNDUP(a, n) ({                                            \
            size_t __n = (size_t)(n);                               \
            (typeof(a))(ROUNDDOWN((size_t)(a) + __n - 1, __n));     \
        })


extern const struct pmem_manager easy_mm;



#endif