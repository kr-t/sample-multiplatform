#include <stdio.h>
#include <stdlib.h>

// #define USE_COMMON

#ifdef USE_COMMON
#include <sample/common.h>
#endif

int main(void)
{
	printf("Hello World\n");
#ifdef USE_COMMON
	printf("%d + %d = %d\n", 2, 3, sum(2, 3));
#endif
	return 0;
}
