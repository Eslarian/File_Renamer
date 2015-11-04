#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[])
{
	char * origFilename;
	char * newFilename;
	char * tokenFilename;
	char * command;
	char * tok;
	char * seasNum;
	char * epNum;
	int x;


	origFilename = malloc(sizeof(char)*80);
	memset(origFilename,'\0',sizeof(char)*80);

	for(x = 1; x < argc; x++)
	{
		strcat(origFilename,argv[x]);
		strcat(origFilename,"\\ ");
	} 
		
	printf("%s",origFilename);	
	
	strcpy(tokenFilename,origFilename);
	tok = strtok(tokenFilename,"0");
	strcpy(seasNum,tok); 
	tok = strtok(NULL,"- ");
	strcpy(epNum,tok);

	newFilename = malloc(sizeof(char)*80);
	memset(newFilename,'\0',sizeof(char)*80);
	strcat(newFilename," Courage\\ The\\ Cowardly\\ Dog-");
	strcat(newFilename,"s0");
	strcat(newFilename,seasNum);
	strcat(newFilename,"e");
	strcat(newFilename,epNum);

	command = malloc(sizeof(char)*80); 
	memset(command,'\0',sizeof(char)*80);
	strcat(command,"mv ");
	strcat(command,origFilename);	
	strcat(command,newFilename);
	strcat(command,".avi");
	printf("%s",command);
	system(command);
		

	return EXIT_SUCCESS;
}
