#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_SIZE 20
char* chomp(char* str);
int main(int argc, char *argv[]){
	const char *restrict filename;
	FILE *reviews;
	char word[MAX_WORD_SIZE] = "";
	char match[MAX_WORD_SIZE];
	long int score = 0;
	int scorecnt = 0;

	if(argc!=2){
		printf("not enough arguments\n");
		exit(0);
	}
	filename = argv[1];
	if(!(reviews = fopen(filename, "r"))){
		printf("no file found\n");
		exit(0);
	}
	printf("Enter a word: ");
	while(!(fgets(word, MAX_WORD_SIZE, stdin))){
		printf("\nTry again: ");
	}
	chomp(word);
	while(fgets(match, MAX_WORD_SIZE, reviews)){
		char* pword = word;
		char* pmatch = match;
		while(*pword == *pmatch && (*pmatch != ' ' || *pword != ' ')){
			pword++;
			pmatch++;
			if(*pmatch==' '||*pmatch == '\n'){
				
			}
		}
	}
}
char * chomp(char * str){
	char* p;
	for(p = str; *p != '\n'; p++);
	*p = '\0';
	return str;
}
