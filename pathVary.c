#include <stdio.h>
#include <string.h>

char *bkDir="/usr/local/share/bkx_backup_directory";

char *varyAdd(char *filePath)
{
	static char cachePath[]="/usr/local/share/bkx_backup_directory";
	strcat(cachePath,filePath);
	return cachePath;
}

char *varySub(char *filePath)
{
	static char cachePath[1024];
	int x1=0,x2=strlen(bkDir);
	while(filePath[x1]!='\0')
	{
		cachePath[x1]=filePath[x1];
		x1++;
	}
	x1=x2;
	while(cachePath[x2]!='\0')
	{
		cachePath[x2]=cachePath[x2+x1];
	}
	return cachePath;
}
