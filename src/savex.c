/* save.c: a part of bkx backup tool. */
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

int save(char *filePath)
{
	char *bkDir="/usr/local/share/bkx_backup_directory";
	char *targetPath=varyAdd(filePath);
	printf("Source Path:%s\nBackup Path:%s\n",filePath,targetPath);
	if(!isFileExist(filePath)) //测试源文件是否存在
		ERROR(5);
	else if(!isFileCanRead(filePath)) //测试源文件是否有读写权限
		ERROR(3);
	else if(isDirectory(filePath)) //测试源文件是否一个目录
		ERROR(4);
	else if(!isFileExist(bkDir)) //测试备份目录是否存在
		ERROR(8);
	else if(!isDirectory(bkDir)||!isFileCanWrite(bkDir)) //测试备份目录是否可写
		ERROR(7);	
	else
	{
		if(isFileExist(targetPath))
	        {
                	if(remove(targetPath)==-1)
                        	ERROR(9);
        	}
		if(fileCopy(filePath,targetPath))
			printf("Backup sucess!\n");
	}
}
