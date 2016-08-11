#include <stdio.h>
#include <string.h>

char chessboard[15][15];
int positionadd[4][2] = {
	-1, 0,	//top
	1, 0,	//bottom
	0, -1,	//left
	0, 1,	//right
};

int horseadd[4][2][2] = {
	-2, -1,	//top
	-2, 1,
	2, -1,	//bottom
	2, 1,
	-1, -2,	//left
	1, -2,
	-1, 2,	//right
	1, 2,
};

int outofbound(int x, int y) {
	if (x >= 1 && x <= 3 && y >= 4 && y <= 6) return 0;
	if (x >= 8 && x <= 10 && y >= 4 && y <= 6) return 0;
	return 1;
}

int outofchess(int x, int y) {
	if (x < 1 || x > 10 || y < 1 || y > 9) return 1;
	else return 0;
}

int isDead(int x, int y) {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == x && j == y) continue;
			if (chessboard[i][j] == 'G') {
				if (j == y) {
					int dead = 1, min, max;
					if (i > x) {
						min = x + 1;
						max = i - 1;
					}
					else {
						min = i + 1;
						max = x - 1;
					}
					for (int k = min; k <= max; k++) {
						if (chessboard[k][j]) {
							dead = 0;
							break;
						}
					}
					if (dead)
						return 1;
				}
			}
			else if (chessboard[i][j] == 'R') {
				if (i == x) {
					int dead = 1, min, max;
					if (j > y) { min = y + 1; max = j - 1;}
					else { min = j + 1; max = y - 1; }
					for (int k = min; k <= max; k++) {
						if (chessboard[i][k]) { dead = 0; break; }
					}
					if (dead)
						return 1;
				}
				else if (j == y) {
					int dead = 1, min, max;
					if (i > x) { min = x + 1; max = i - 1; }
					else { min = i + 1; max = x - 1; }
					for (int k = min; k <= max; k++) {
						if (chessboard[k][j]) { dead = 0; break; }
					}
					if (dead) 
						return 1;
				}
			}
			else if (chessboard[i][j] == 'H') {
				for (int k = 0; k < 4; k++) {
					if (outofchess(i + positionadd[k][0], j + positionadd[k][1])
						|| chessboard[i + positionadd[k][0]][j + positionadd[k][1]])
						continue;
					for (int h = 0; h < 2; h++) {
						int newx = i + horseadd[k][h][0];
						int newy = j + horseadd[k][h][1];
						if (newx == x && newy == y)
							return 1;
					}
				}
			}
			else if (chessboard[i][j] == 'C') {
				if (i == x) {
					int obstacle = 0, min, max;
					if (j > y) { min = y + 1; max = j - 1; }
					else { min = j + 1; max = y - 1; }
					for (int k = min; k <= max; k++) {
						if (chessboard[i][k]) obstacle++;
					}
					if (obstacle == 1) 
						return 1;
				}
				else if (j == y) {
					int obstacle = 0, min, max;
					if (i > x) {min = x + 1; max = i - 1;}
					else { min = i + 1; max = x - 1; }
					for (int k = min; k <= max; k++) {
						if (chessboard[k][j]) obstacle++;
					}
					if (obstacle == 1)
						return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	int n, gx, gy;
	while (scanf("%d%d%d", &n, &gx, &gy) == 3 && n != 0) {
		memset(chessboard, 0, sizeof(chessboard));
		for (int i = 0; i < n; i++) {
			char c;
			int x, y;
			getchar();
			scanf("%c%d%d", &c, &x, &y);
			chessboard[x][y] = c;
		}
		int dead = 1;
		for (int i = 0; i < 4; i++) {
			int newgx = gx + positionadd[i][0];
			int newgy = gy + positionadd[i][1];
			if (outofbound(newgx, newgy)) continue;
			if (!isDead(newgx, newgy)) {
				dead = 0;
				break;
			}
		}
		if (dead) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
}