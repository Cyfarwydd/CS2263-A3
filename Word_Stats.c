#include "Word_Stats.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_LENGTH 200


void getWordStats(char *word, FILE *f, int *sum, int *num){
	char match[MAX_WORD_LENGTH];
	int score = 0;
	int cnt = 0;
	int tmp = 0;
	int lineScore = 0;
	int matched = 0;
	while(fgets(match, MAX_WORD_LENGTH, f)){
		char matchWord[MAX_WORD_LENGTH];
		int p1;
		while(match[p1] != '\0'){
			while(p1!=0){
				match[p1] = ' ';
				p1--;
			}
			while(match[p1] == ' '){	// iterator
				p1++;
			}
			while(match[p1] != ' ' && match[p1] != '\\'){
				p1++;
			}
			//*p1 = '';
			strcpy(matchWord, match);
			match[0] = match[p1];
			//strncpy(matchWord, match, wordSize);
			checkScore(matchWord, &tmp);
			if(tmp == -1){
				tmp = checkWord(matchWord, word, MAX_WORD_LENGTH);
				if(tmp==1){
					score += lineScore;
					cnt ++;
					break;
				}
			}else{
				lineScore = tmp;
			}
		}
	}
	sum = &cnt;
	num = &score;
}

void checkScore(char* match, int *score){
	char* p1 =  match;
	if((*p1 >= 'A' && *p1 <= 'Z')||(*p1 >= 'a' && *p1 <= 'z')){
		*score = -1;
	}else{
		if(*p1 >= '0' && *p1 <= '9'){
			*score = *p1 - 48;
		}else{
			*score = -1;
		}
	}
}

int checkWord(char* match, char* word, int max_len){
	char* pm = match;
	char* pw = word;
	while(*pm != *pw && (*(pm-1) == ' ' || (pm-1) < match)){
		pm++;
	}
	while((*pm == *pw) && (*pm != ' ' || *pw != ' ')){
		pm++;
		pw++;
		if((*pm == ' ' || *pm == '\\') && (*pw == ' ' || *pw == '\\')){
			//it cycled through every letter and it matched!
			return 1;
		}
	}
	
	return 0;
}
