#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int isFileExist(char *route)
{
	if(access(route,F_OK)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFileCanRead(char *route)
{
	if(access(route,R_OK)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}		
}

int isFileCanWrite(char *route)
{
        if(access(route,W_OK)==0)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int isDirectory(char *route)
{
	struct stat fileInfo;
	stat(route,&fileInfo);
	if(S_ISDIR(fileInfo.st_mode))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
