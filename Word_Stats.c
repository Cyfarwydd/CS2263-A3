#include "Word_Stats.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 200
#define MAX_WORD_SIZE 50

void getWordStats(char *word, FILE *f, int *sum, int *num){
	char *line, *pline;
	char nextLine[MAX_LINE_SIZE];
	line = fgets(nextLine, MAX_LINE_SIZE, f);
	int *p = line;
	int score;
	int cnt = 0;
	int lineScore;
	while(line){
		pline = strtok(line, " ");
		lineScore = *pline-48;
		pline = strtok(NULL, " ");
		while(pline){
			if(strcmp(pline, word) == 0){
				score = lineScore;
				sum = &score;
				cnt ++;
				num = &cnt;
			}
			pline = strtok(NULL, " ");
		}
		line = fgets(nextLine, MAX_LINE_SIZE, f);
	}
	printf("\n%s appeared %d times\n", word, *sum);
	printf("The average score for reviews containing %s is %f\n", word, (float)*sum/ *num);
}
