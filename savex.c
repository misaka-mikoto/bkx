#include <stdio.h>

int saveBK(char *filePath)
{
	char *bkDir;
	bkDir="/usr/local/share/bkx_backup_directory";
	char *targetPath=varyAdd(filePath);
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
//	else if(!isFileExist())
		
	else if(isFileExist(targetPath))
	{
		if(remove(targetPath)==-1)
			ERROR(9);
	}
	else
	{
		        printf("1");
		if(fileCopy(filePath,targetPath))
			printf("Copy sucess!\n");
	}
}
