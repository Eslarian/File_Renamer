#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tinydir.h"

#define COLOR_ERROR	"\x1b[1;31m"	// red 
#define COLOR_RESET "\x1b[0m"      //reset

#define RROL(x) x[strlen(x)-1]

int main(int argc, char * argv[])
{
	char * command;
	char * fileName;
	char * fileExtension;
	char * seasNum;
	char epNum[3];
	int x;

	tinydir_dir dir;
	tinydir_file file;

	//I like terminal colors 
	if(argc != 4) {
		fprintf(stderr,"%sUsage: ./Renamer path/to/show/",COLOR_ERROR);
		fprintf(stderr,"Show\\ Name seasonNumber\n%s",COLOR_RESET);
		return EXIT_FAILURE;
	} 

	//Open directory of the files to be renamed
	tinydir_open(&dir,argv[1]);
	seasNum = argv[3];
	
	command = malloc(sizeof(char)*80);
	x = 1;

	while(dir.has_next) {
		tinydir_readfile(&dir, &file);
		
		if (file.name[0] == '.') {
			printf("skipping \"%s\"", file.name);
			tinydir_next(&dir);
			continue;
		}

		snprintf(epNum,3,"%d",x);	
		fileName = file.name;
		fileExtension = file.extension;	
		 
		memset(command,'\0',sizeof(char)*80);

		strcat(command,"mv ");
		strcat(command,argv[1]);
		strcat(command,file.name);
		strcat(command,"/ ");
		strcat(command,argv[2]);
		strcat(command," - ");
		strcat(command,"S");
		strcat(command,seasNum);
		strcat(command,"E");
		strcat(command,epNum);
		strcat(command,".");
		strcat(command,fileExtension);
	
		tinydir_next(&dir);
		x++; 
		printf("%s\n",command);
		//system(command);
	} 

	tinydir_close(&dir);
	free(command);	
	
	return EXIT_SUCCESS;
}
