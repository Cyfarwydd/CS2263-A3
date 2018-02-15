#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_SIZE 20

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("not enough arguments\n");
		exit(0);
	}
	const char * restrict filename = argv[1];
		
	printf("%s", filename);
	FILE * reviews; 
	if(!(reviews = fopen(filename, "r"))){
		printf("no file found\n");
		exit(0);
	}
	char * word = "quiet";
	char match[MAX_WORD_SIZE];
	while(fgets(match, MAX_WORD_SIZE, reviews)){
		char* pword = word;
		char* pmatch = match;
		while(*pword == *pmatch && (*pmatch != ' ' || *pword != ' ')){
			printf("win\n");
			pword++;
			pmatch++;
		}
	}
}
