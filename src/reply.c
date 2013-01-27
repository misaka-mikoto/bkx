/* reply.c: a part of bkx backup tool. */
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

int reply(char *sourcePath)
{
        char *bkDir="/usr/local/share/bkx_backup_directory";
        char *backupPath=varyAdd(sourcePath);
        printf("Backup Path:%s\nReply Path:%s\n",backupPath,sourcePath);
	if(!isFileExist(backupPath)) //测试备份文件是否存在
                ERROR(10);
        else if(!isFileCanRead(backupPath)) //测试备份文件是否有读权限
                ERROR(7);
        else if(isDirectory(backupPath)) //测试备份件是否一个目录
                ERROR(10);
        else
        {
		if(isFileExist(sourcePath))
        	{
                	if(remove(sourcePath)==-1)
                        	ERROR(9);
        	}
                if(fileCopy(backupPath,sourcePath))
                        printf("Reply sucess!\n");
        }
}
