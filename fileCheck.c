#include <stdio.h>
#include <unistd.h>

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
