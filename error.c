#include <stdio.h>

void ERROR(int errNum)
{
	printf("error%d:",errNum);
	switch (errNum)
		{
		case 1:
			printf("Please input the file route after parameter, or input 'bkx --help' for help.");
			break;
		case 2:
			printf("Please don't input more then one parameter, or input 'bkx --help' for help.");
			break;
		case 3:
			printf("I don't have permission to read the target file!");
			break;
		case 4:
			printf("I don't support directory backup.");
			break;
		case 5:
			printf("Target doesn't exist!");
			break;
		}
	printf("\n");
}
