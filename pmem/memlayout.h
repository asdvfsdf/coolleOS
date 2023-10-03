#ifndef __MEMLAYOUT_H__
#define __MEMLAYOUT_H__

#include "list.h"
#include "stddef.h"

#define offsetof(type, member)                                      \
    ((size_t)(&((type *)0)->member))

#define to_struct(ptr, type, member)                               \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define le2page(le, member)                 \
    to_struct((le), struct page, member)

#endif