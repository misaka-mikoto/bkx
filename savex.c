#include <stdio.h>

int saveBK(char *routeChar)
{
	if(!isFileExist(routeChar))
		ERROR(5);
	else if(isDirectory(routeChar))
		ERROR(4);
	else
	{
		fileCopy(routeChar,"./textfile");
	}
}
