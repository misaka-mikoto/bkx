#include <stdio.h>

int saveBK(char *routeChar)
{
	printf("CHAR:%s\n",routeChar);
	if(!isFileExist(routeChar))
		ERROR(5);
	if(isDirectory(routeChar))
		ERROR(4);
}
