#ifndef __LINK_H__
#define __LINK_H__

#include "stdint.h"

typedef struct link
{
    u64 page;
    struct link* next;

}Link;

Link* initLink();



#endif