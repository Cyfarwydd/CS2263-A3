#include <stdio.h>
#include <stdlib.h>
#ifndef Word_Stats_h
#define Word_Stats_h
void getWordStats(char *word, FILE *f, int *sum, int *num);
void checkScore(char* match, int *score);
int checkWord(char* match, char* word, int max_len);

#endif /* Word_Stats_h */
