#include <stdio.h>
#include <string.h>
char dict[128][10];
char words[110][11];
char morse[110][100];

int compare(char m[], char morse[]) {
	for (int i = 0; i < strlen(m) && i < strlen(morse); i++) {
		if (m[i] != morse[i]) return -1;
	}
	int diff = strlen(m) - strlen(morse);
	return diff > 0 ? diff : -diff;
}

int main() {
	char c[2];
	while (scanf("%s", c) != EOF && c[0] != '*') {
		scanf("%s", dict[c[0]]);
	}
	int wordsnum = 0;
	while (scanf("%s", words[wordsnum]) != EOF && words[wordsnum][0] != '*')
		wordsnum++;
	for (int i = 0; i < wordsnum; i++) {
		morse[i][0] = '\0';
		for (int j = 0; j < strlen(words[i]); j++) {
			strcat(morse[i], dict[words[i][j]]);
		}
	}
	char m[100];
	while (scanf("%s", m) != EOF && m[0] != '*') {
		int isMate = 0, diff = -1, index = -1;
		for (int i = 0; i < wordsnum; i++) {
			int t = compare(m, morse[i]);
			if (t == 0) {
				if (!isMate)	
					index = i;
				isMate++;
			}
			else if (t > 0 && !isMate){
				if (diff < 0 || (diff > 0 && diff > t)) {
					diff = t;
					index = i;
				}
			}
		}
		if (isMate) {
			printf("%s", words[index]);
			if (isMate > 1) {
				printf("!");
			}
			printf("\n");
		}
		else {
			printf("%s?\n", words[index]);
		}
	}
	return 0;
}