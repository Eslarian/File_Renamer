#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RROL(x) x[strlen(x)-1]

int main(int argc, char * argv[])
{
	char * origFilename;
	char * newFilename;
	char * tokenFilename;
	char * command;
	char * tok;
	char * seasNum;
	char * epNum;
	int x,y;


	origFilename = malloc(sizeof(char)*80);
	memset(origFilename,'\0',sizeof(char)*80);
	
	tokenFilename = malloc(sizeof(char)*80);
	memset(tokenFilename,'\0',sizeof(char)*80);

	tok = strtok(argv[1]," ");
	while(tok != NULL)
	{
		strcat(origFilename,tok);
		tok = strtok(NULL," ");
		if(tok != NULL)
			strcat(origFilename,"\\ ");
	}
	
	printf("%s\n",origFilename);

	strcpy(tokenFilename,origFilename);
	tok = strtok(tokenFilename,"0");
	seasNum = malloc(sizeof(tok));
	strcpy(seasNum,tok); 
	tok = strtok(NULL,"- ");
	epNum = malloc(sizeof(tok));
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
	printf("%s\n",command);
	system(command);

	free(origFilename);
	free(newFilename);
	free(command);
	free(tokenFilename);
	free(seasNum);
	free(epNum);

	return EXIT_SUCCESS;
}
