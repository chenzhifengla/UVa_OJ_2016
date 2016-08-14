#include <stdio.h>
#include <string.h>
char board[10][10];
int add[9][2] = {
	0, 0,
	0, -1,
	-1, -1,
	-1, 0,
	-1, 1,
	0, 1,
	1, 1,
	1, 0,
	1, -1,
};

void printBoard() {
	for (int i = 1; i <= 8; i++) {
		printf("%s\n", board[i] + 1);
	}
}

int isLegal(char player, char player2, int x, int y) {
	for (int i = 1; i <= 8; i++) {
		int newx = x + add[i][0], newy = y + add[i][1];
		if (board[newx][newy] != player2) continue;
		do {
			newx += add[i][0];
			newy += add[i][1];
			if (board[newx][newy] == player) {
				return i;
			}
			else if (board[newx][newy] == '-' || !board[newx][newy]) break;
		} while (newx >= 1 && newx <= 8 && newy >= 1 && newy <= 8);
	}
	return 0;
}

void list(char player) {
	char player2 = player == 'W' ? 'B' : 'W';
	int legalnum = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (board[i][j] != '-') continue;
			if (isLegal(player, player2, i, j)) {
				legalnum++;
				if (legalnum > 1) printf(" ");
				printf("(%d,%d)", i, j);
			}
		}
	}
	if (legalnum) printf("\n");
	else printf("No legal move.\n");
}

int move(char player, int x, int y) {
	char player2 = player == 'W' ? 'B' : 'W';
	int isChange = 1;
	int direct = isLegal(player, player2, x, y);
	if (!direct) {
		char t = player;
		player = player2;
		player2 = t;
		direct = isLegal(player, player2, x, y);
		isChange = 0;
	}
	while (board[x][y] != player) {
		board[x][y] = player;
		x += add[direct][0];
		y += add[direct][1];
	}
	int black = 0, white = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (board[i][j] == 'W') white++;
			else if (board[i][j] == 'B') black++;
		}
	}
	printf("Black -%3d White -%3d\n", black, white);
	return isChange;
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
			if (cmd[0] == 'Q') {
				printBoard();
				break;
			}
			else if (cmd[0] == 'L') {
				list(currentplayer[0]);
			}
			else if (cmd[0] == 'M') {
				if (move(currentplayer[0], cmd[1] - '0', cmd[2] - '0'))
					currentplayer[0] = currentplayer[0] == 'W' ? 'B' : 'W';
			}
		}
		if (kase) printf("\n");
	}
	return 0;
}