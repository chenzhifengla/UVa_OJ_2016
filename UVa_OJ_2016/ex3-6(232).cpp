#include <cstdio>
#include <cstring>

int main() {
	char buf[15][15];
	int num[15][15] = { 0 };
	int across[15][15], down[15][15];
	int row, column;
	int cases = 0;
	while (scanf("%d", &row) != EOF && row != 0) {
		scanf("%d", &column);
		memset(buf, 0, sizeof(buf));
		for (int i = 0; i < row; i++) {
			scanf("%s", buf[i]);
		}
		memset(num, 0, sizeof(num));
		memset(across, 0, sizeof(across));
		memset(down, 0, sizeof(down));
		int number = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (buf[i][j] == '*') continue;
				if (j == 0 || buf[i][j - 1] == '*') {
					across[i][j] = 1;
				}
				if (i == 0 || buf[i - 1][j] == '*') {
					down[i][j] = 1;
				}
				if (across[i][j] || down[i][j]) {
					num[i][j] = ++number;
				}
			}
		}
		if (cases > 0) printf("\n");
		printf("puzzle #%d:\n", ++cases);
		printf("Across\n");
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (across[i][j]) {
					printf("%3d.", num[i][j]);
					while (buf[i][j] != '*' && buf[i][j]) {
						printf("%c", buf[i][j]);
						j++;
					}
					printf("\n");
				}
			}
		}
		printf("Down\n");
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (down[i][j]) {
					printf("%3d.", num[i][j]);
					int t = i;
					while (buf[t][j] != '*' && buf[t][j]) {
						printf("%c", buf[t][j]);
						t++;
					}
					printf("\n");
				}
			}
		}
	}
}