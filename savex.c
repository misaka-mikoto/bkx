#include <stdio.h>

int save(char *filePath)
{
	char *bkDir="/usr/local/share/bkx_backup_directory";
	char *targetPath=varyAdd(filePath);
	printf("Source Dir:%s\nBackup Dir:%s\n",filePath,targetPath);
	if(!isFileExist(filePath)) //测试源文件是否存在
		ERROR(5);
	else if(!isFileCanRead(filePath)) //测试源文件是否有读写权限
		ERROR(3);
	else if(isDirectory(filePath)) //测试源文件是否一个目录
		ERROR(4);
	else if(!isFileExist(bkDir)) //测试备份目录是否存在
		ERROR(8);
	else if(!isDirectory(bkDir)||!isFileCanWrite(bkDir)) //测试备份目录是否可写
		ERROR(7);	
	else
	{
		if(isFileExist(targetPath))
	        {
                	if(remove(targetPath)==-1)
                        	ERROR(9);
        	}
		if(fileCopy(filePath,targetPath))
			printf("Backup sucess!\n");
	}
}
