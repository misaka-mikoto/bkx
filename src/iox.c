#include <stdio.h>
#include <memory.h>

int makeDir(char *filePath)
{
	char cachePath[1024]={0};
	int i=0;
	while(filePath[i]!='\0')
	{
        	cachePath[i]=filePath[i];
        	if(filePath[i+1]=='/')
         		if(!isFileExist(cachePath))
			{
                		mkdir(cachePath);
                		printf("MKDIR:%s\n",cachePath);
          		}
        		i++;
	}
	return 1;
}

int fileCopy(char *sorceFile,char *targetFile)
{
	FILE *sF,*oF;
	char buffer[1024]={0};
	int len;
	makeDir(targetFile);
	if((sF=fopen(sorceFile,"r"))==NULL)
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
