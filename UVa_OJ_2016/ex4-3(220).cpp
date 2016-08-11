#include <stdio.h>
#include <string.h>
char board[10][10];
int add[8][2] = {
	0, -1,
	-1, -1,
	-1, 0,
	-1, 1,
	0, 1,
	1, 1,
	1, 0,
	1, -1,
};

void list(char player) {
	char player2 = player == 'W' ? 'B' : 'W';
	int legalnum = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (board[i][j] != '-') continue;
			int isLegal = 0;
			for (int k = 0; k < 8; k++) {
				int newx = i + add[k][0], newy = j + add[k][1];
				if (board[newx][newy] != player2) continue;
				newx += add[k][0]; newy += add[k][1];
				while (newx >= 1 && newx <= 8 && newy >= 1 && newy <= 8) {
					if (board[newx][newy] == player) {
						isLegal = 1;
						break;
					}
					else if (board[newx][newy] == '-') break;
				}
				if (isLegal) break;
			}
			if (isLegal) {
				legalnum++;
				if (legalnum > 1) printf(" ");
				printf("(%d,%d)", i, j);
			}
		}
	}
	if (legalnum) printf("\n");
	else printf("No legal move.\n");
}

void move(char player, int x, int y) {
	char player2 = player == 'W' ? 'B' : 'W';

}

int main() {
	int kase;
	scanf("%d", &kase);
	while (kase--) {
		memset(board, 0, sizeof(board));
		for (int i = 1; i < 9; i++) {
			scanf("%s", board[i] + 1);
		}
		char currentplayer[5];
		scanf("%s", currentplayer);
		char cmd[5];
		while (1) {
			scanf("%s", cmd);
			if (cmd[0] == 'Q') break;
			else if (cmd[0] == 'L') {
				list(currentplayer[0]);
			}
			else if (cmd[0] == 'M') {
				move(currentplayer[0], cmd[1] - '0', cmd[2] - '0');
			}
		}
		if (kase) printf("\n");
	}
	return 0;
}