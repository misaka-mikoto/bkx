/* bkx.c: a part of bkx backup tool. */
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
#include <getopt.h>
#include <limits.h>
#include <stdlib.h>

char *filePath;
char* const shortOptions = "s:r:h";
struct option longOptions[] = {
	{"help", 0, NULL, 'h' },
	};

main(int argc, char *argv[])
{
	int opt;
	int tempVar=0;
	if(argc>3) ERROR(2);
	else if(argc<2) ERROR(1);
	else
	{
		while ((opt=getopt_long (argc, argv, shortOptions, longOptions, NULL))!=-1)
		{
				switch (opt)
				{
				case 's':
					if(isFileExist(optarg))
					{
						filePath=realpath(optarg,NULL);
						save(filePath);
					}
					else ERROR(5);
					break;
				case 'r':
					if(!isFileExist(optarg))
					mkdir(optarg);
					filePath=realpath(optarg,NULL);
					reply(filePath);
					break;
				case 'h':
					help();
					break;
				}
				tempVar++;
		}
		if(tempVar==0) ERROR(1);
	}
	return 0;
}
