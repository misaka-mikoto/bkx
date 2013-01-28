/* pathVary.c: a part of bkx backup tool. */
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
#include <string.h>

char *varyAdd(char *filePath)
{
	static char cachePath[]="/usr/local/share/bkx_backup_directory";
	strcat(cachePath,filePath);
	return cachePath;
}

//char *varySub(char *filePath)
//{
//	static char cachePath[1024]={0};
//	int x1=0,x2=strlen("/usr/local/share/bkx_backup_directory");
//	while(filePath[x1]!='\0')
//	{
//		cachePath[x1]=filePath[x1];
//		x1++;
//	}
//	x1=x2;
//	while(cachePath[x2]!='\0')
//	{
//		cachePath[x2]=cachePath[x2+x1];
//	}
//	return cachePath;
//}

char *pathDir(char *filePath)
{
	static char cachePath[1024]={0};
	int x1=0,x2=0;
	while(filePath[x1]!='\0')
	{
        	if(filePath[x1]=='/')
       		x2=x1;
        	x1++;
	}
	x1=0;
	while(x1<x2)
	{
        	cachePath[x1]=filePath[x1];
        	x1++;
	}
	return cachePath;
}
