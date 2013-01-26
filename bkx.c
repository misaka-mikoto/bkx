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
	int c;
	if(argc>3) ERROR(2);
	else
	{
		while ((c=getopt_long (argc, argv, shortOptions, longOptions, NULL))!=-1)
		{
				switch (c)
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
		}
	}
	return 0;
}
