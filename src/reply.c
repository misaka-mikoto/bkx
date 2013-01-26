#include <stdio.h>

int reply(char *sourcePath)
{
        char *bkDir="/usr/local/share/bkx_backup_directory";
        char *backupPath=varyAdd(sourcePath);
        printf("Backup Dir:%s\nReply Dir:%s\n",backupPath,sourcePath);
	if(!isFileExist(backupPath)) //测试备份文件是否存在
                ERROR(10);
        else if(!isFileCanRead(backupPath)) //测试备份文件是否有读权限
                ERROR(7);
        else if(isDirectory(backupPath)) //测试备份件是否一个目录
                ERROR(10);
        else
        {
		if(isFileExist(sourcePath))
        	{
                	if(remove(sourcePath)==-1)
                        	ERROR(9);
        	}
                if(fileCopy(backupPath,sourcePath))
                        printf("Reply sucess!\n");
        }
}
