#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_SIZE 20
int main(int argc, char *argv[]){
	const char *filename;
	FILE *reviews;
	char word[MAX_WORD_SIZE];
	char *pw = word;
	int sum = 0, count = 0;

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
	fgets(word, MAX_WORD_SIZE, stdin);
	pw = strtok(word, "\n");
	getWordStats(pw, reviews, sum, count);
	return 1;
}
