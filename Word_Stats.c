#include "Word_Stats.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_LENGTH 200

void getWordStats(char *word, FILE *f, int *sum, int *num){
	char match[MAX_WORD_LENGTH];
	int score = 0;
	int lineScore = 0;
	int matched = 0;
	while(fgets(match, MAX_WORD_LENGTH, f)){
		char* matchWord;
		getWord(match, matchWord);
		checkWord(matchWord, word, MAX_WORD_LENGTH);

	}
}

void checkScore(char* match, int *score){
	char** nextPointer =  &match;
	if(isdigit(match)){
		*score = strtol(match, nextPointer, 10);
	}else{
		*score = -1;
	}
}

int checkWord(char* match, char* word, int max_len){
	char* pm = match;
	char* pw = word;
	while(*pm != *pw){
		pm++;
	}
	while((*pm != '\0' && pw != '\0') || (pm - match == max_len || pw - match == max_len) ){
		if(*pm == *pw){
			pm++;
			pw++;
		}else{
			return 0;
		}
	}
	return 1;
}

void getWord(char* match, char* word){
	char* pm = match;
	char* pw = word;
	while(*pm != ' ' || *pm != '\n'){
		*pw = *pm;
		pw++;
		pm++;
	}
}
