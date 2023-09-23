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

// char *strcpy(char *ret, register const char *s2)
// {
//     register char *s1 = ret;

//     while (*s1++ = *s2++)

//     return ret;
// }