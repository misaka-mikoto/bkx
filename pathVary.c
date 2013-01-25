#include <stdio.h>
#include <syslib.h>

char *bkDir;
bkDir="/usr/local/share/bkx_backup_directory";

char *varyAdd(char *filePath)
{
	static char cachePath[]=bkDir;
	strcat(cachePath,filePath);
	return cachePath;
}

int varySub(char *filePath)
{
	
}
