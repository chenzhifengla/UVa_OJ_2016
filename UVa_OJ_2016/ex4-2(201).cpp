#include <stdio.h>
#include <string.h>
int square[10][10][2];
int n, m;

int countSquare(int size) {
	int num = 0;
	for (int i = 1; i <= n - size; i++) {
		for (int j = 1; j <= n - size; j++) {
			int isSquare = 1;
			for (int k = 0; k < size; k++) {
				if (!square[i][j + k][0]) { isSquare = 0; break; }
				if (!square[i + k][j][1]) { isSquare = 0; break; }
				if (!square[i + size][j + k][0]) { isSquare = 0; break; }
				if (!square[i + k][j + size][1]) { isSquare = 0; break; }
			}
			if (isSquare) num++;
		}
	}
	if (num) printf("%d square (s) of size %d\n", num, size);
	return num;
}

int main() {
	int kase = 0;
	while (scanf("%d", &n) != EOF) {
		if (kase) {
			printf("\n**********************************\n\n");
		}
		printf("Problem #%d\n\n", ++kase);
		int hasSquares = 0;
		memset(square, 0, sizeof(square));
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			char direction[5];
			int x, y;
			scanf("%s%d%d", direction, &x, &y);
			if (direction[0] == 'H') {
				square[x][y][0] = 1;
			}
			else square[y][x][1] = 1;
		}
		for (int size = 1; size <= n - 1; size++) {
			if (countSquare(size)) hasSquares = 1;
		}
		if (!hasSquares) printf("No completed squares can be found.\n");
	}
	return 0;
}