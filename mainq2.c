#include "Word_Stats.h"
#define MAX_LINE_SIZE 200

int main(){
	char *line, *review;
	fgets(*line, MAX_LINE_SIZE, stdin);
	review = strtok(line, '\n');
	while(review){
		printf("%s ", review);
	}
	return 1;
}
