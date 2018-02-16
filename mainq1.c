#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_SIZE 20
int main(int argc, char *argv[]){
	const char *filename;
	FILE *reviews;
	char word[MAX_WORD_SIZE];
	char match[MAX_WORD_SIZE];
	int score;
	int scoreAvg = 0;
	int scoreNum = 0;

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
	int i;
	for(i = 0; word[i] != '\n'; i++){
	}
	word[i] = '\0';
	getWordStats(word, reviews, scoreNum, scoreAvg);
	if (scoreNum !=0){
		printf("%s appeared %d times\n", word, scoreNum);
		float avg = scoreAvg/scoreNum;
		printf("The average score for reviews containing %s is %f", word, avg);
	}
	return 1;
}
