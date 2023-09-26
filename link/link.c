#include "link.h"
#include "stdio.h"
#include "string.h"

Link* initLink(u64 kernel_end, u64 page_num){
    int i = 0;
    Link* p = NULL;

    Link* temp = (Link*)&((struct link){0,NULL});

    p = temp;

    for(int i = 1;i < page_num;i++){

        Link* a = (Link*)&((struct link){0,NULL});
        temp->page = i;
        temp->next = NULL;
        temp->next = a;
        temp = temp->next;

    }

    return p;

}

