#include <stdio.h>
#include <memory.h>

int fileCopy(char *sorceFile,char *targetFile)
{
	printf("1");
	FILE *sF,*oF;
	char buffer[1024];
	char *targetDir=pathDir(targetFile);
	int len;
	if(!isFileExist(targetDir))
	{
		
	}
	else if((sF=fopen(sorceFile,"r"))==NULL)
	{
		ERROR(6);	
	}
	else if((oF=fopen(targetFile,"w"))==NULL)
	{
		ERROR(6);
	}
	else
	{
		while((len=fread(buffer,1,1024,sF))>0)
		{
			fwrite(buffer,1,len,oF);
			memset(buffer,0,1024);
		}
	fclose(oF);
	fclose(sF);
	return 1;
	}
	return 0;
}
