#include "slice.h"



slice creat_slice(int *arr,size_t len){
    slice slice;
    slice.data = arr;
    slice.len = len;
    return slice;
}


int get_element(const slice *slice,size_t idx){
    if(idx < slice->len){
        return slice->data[idx];
    }else{
        panic("Index out of bounds\n");
        return 0;
    }

}