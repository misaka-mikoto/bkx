#include <stdio.h>

int saveBK(char *routeChar)
{
	printf("CHAR:%s\n",routeChar);
	if(!isFileExist(routeChar))
		ERROR(5);
}
