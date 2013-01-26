/* error.c: a part of bkx backup tool. */
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

void ERROR(int errNum)
{
	printf("error%d:",errNum);
	switch (errNum)
		{
		case 1:
			printf("Please input file path after parameter, or input 'bkx --help' for help.");
			break;
		case 2:
			printf("Please don't input more then one parameter, or input 'bkx --help' for help.");
			break;
		case 3:
			printf("Plz use super user!");
			break;
		case 4:
			printf("I don't support directory backup.");
			break;
		case 5:
			printf("Target doesn't exist!");
			break;
		case 6:
			printf("Copy Error!");
			break;
		case 7:
			printf("Plz use super user.");
			break;
		case 8:
			printf("Please create the backup file directory yourself.(/usr/local/share/bkx_backup_directory)");
			break;
		case 9:
			printf("File delete error!");
			break;
		case 10:
			printf("reply error!");
			break;
		}
	printf("\n");
}
