#include <stdio.h>

int saveBK(char *routeChar)
{
	printf("CHAR:%s\n",routeChar);
	if(!isFileExist(routeChar))
		ERROR(5);
	else if(isDirectory(routeChar))
		ERROR(4);
	else
	{
		printf("OK\n");
	}
}
