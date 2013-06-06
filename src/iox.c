/* iox.c: a part of bkx backup tool. */
/*  Copyright (C) 2013 Wu Liwei
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
