#include <cstdio>

bool outOfBound(int x, int y) {
	if (x >= 5 || x < 0 || y < 0 || y >= 5) return true;
	else return false;
}

int main() {
	int cases = 0;
	char buf[5][6] = { 0 };
	char tmp[5];
	int blankx, blanky;
	while (1) {
		scanf("%s", buf[0]);
		if (buf[0][0] == 'Z' && !buf[0][1]) break;
		scanf("%[\r\n]", tmp);
		for (int i = 1; i < 5; i++) {
			scanf("%[^\r\n]", buf[i]);
			scanf("%[\r\n]", tmp);
		}
		//find the blank position
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (buf[i][j] == ' ') {
					blankx = i;
					blanky = j;
					break;
				}
			}
			/*
			if (!buf[i][4]) {
				blankx = i;
				blanky = 4;
				break;
			}*/
		}
		char c;
		bool noOutput = false;
		while ((c = getchar()) != '0') {
			if (noOutput) continue;
			switch (c) {
			case 'A': {
				if (outOfBound(blankx - 1, blanky)) {
					noOutput = true;
				}
				else {
					buf[blankx][blanky] = buf[blankx - 1][blanky];
					buf[blankx - 1][blanky] = ' ';
					blankx--;
				}
				break;
			}
			case 'B': {
				if (outOfBound(blankx + 1, blanky)) {
					noOutput = true;
				}
				else {
					buf[blankx][blanky] = buf[blankx + 1][blanky];
					buf[blankx + 1][blanky] = ' ';
					blankx++;
				}
				break;
			}
			case 'L': {
				if (outOfBound(blankx, blanky - 1)) {
					noOutput = true;
				}
				else {
					buf[blankx][blanky] = buf[blankx][blanky - 1];
					buf[blankx][blanky - 1] = ' ';
					blanky--;
				}
				break;
			}
			case 'R': {
				if (outOfBound(blankx, blanky + 1)) {
					noOutput = true;
				}
				else {
					buf[blankx][blanky] = buf[blankx][blanky + 1];
					buf[blankx][blanky + 1] = ' ';
					blanky++;
				}
				break;
			}
			default:break;
			}
		}
		//output answer
		if (cases > 0) printf("\n");
		printf("Puzzle #%d:\n", ++cases);
		if (noOutput) {
			printf("This puzzle has no final configuration.\n");
		}
		else {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%c ", buf[i][j]);
				}
				printf("%c\n", buf[i][4]);
			}
		}
	}
	return 0;
}