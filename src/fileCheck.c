/*fileCheck.c: a part of bkx backup tool. */
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
