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
			printf("Backup directory error! Plz use super user.");
			break;
		case 8:
			printf("Please create the backup file directory yourself.(/usr/local/share/bkx_backup_directory)");
			break;
		case 9:
			printf("File delete error!");
			break;
		}
	printf("\n");
}
