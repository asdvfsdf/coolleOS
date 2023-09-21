#include "sbi.h"
#include "string.h"
#include "stdio.h"
#include "time.h"


void main()
{
    long value = 0;

    value = sbi_get_spec_version();

    printf("%d\n",value);

}