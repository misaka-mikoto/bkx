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
	else if(argc<3&&argv[1]!="h") ERROR(1);
	else
	{
		while ((c=getopt_long (argc, argv, shortOptions, longOptions, NULL))!=-1)
		{
			switch (c)
			{
			case 's':
				filePath=realpath(optarg,NULL);
				//printf("%s\n",filePath);
				saveBK(absolutePath);
				break;
			case 'r':
				filePath=realpath(optarg,NULL);
				printf("%s\n",filePath);
				break;
			case 'h':
				printf("help\n");
				break;
			}
		}
	}
	return 0;
}
