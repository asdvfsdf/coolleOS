#include "string.h"

int strlen(const char *str)
{
	int ret=0;
	while (*str)
	{
		ret++;
		str++;
	}
	return ret;
}
