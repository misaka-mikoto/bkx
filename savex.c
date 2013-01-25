#include <stdio.h>

int saveBK(char *routeChar)
{
	char *bkDir;
	bkDir="/usr/local/share/bkx_backup_directory";
	if(!isFileExist(routeChar))
		ERROR(5);
	else if(!isFileCanRead(routeChar))
		ERROR(3);
	else if(isDirectory(routeChar))
		ERROR(4);
	else if(!isFileExist(bkDir))
		ERROR(8);
	else if(!isDirectory(bkDir)||!isFileCanWrite(bkDir))
		ERROR(7);
	else
	{
		printf("ok");
	}
}
