#include <stdio.h>

int saveBK(char *filePath)
{
	char *bkDir;
	bkDir="/usr/local/share/bkx_backup_directory";
	if(!isFileExist(filePath))
		ERROR(5);
	else if(!isFileCanRead(filePath))
		ERROR(3);
	else if(isDirectory(filePath))
		ERROR(4);
	else if(!isFileExist(bkDir))
		ERROR(8);
	else if(!isDirectory(bkDir)||!isFileCanWrite(bkDir))
		ERROR(7);
	else
	{
		char *a=varyAdd(filePath);
		printf("%s\n",a);
		char *b=varySub("/usr/local/share/bkx_backup_directory/home/ikaros/bkx/iox.c");
		printf("%s\n",b);
	}
}
