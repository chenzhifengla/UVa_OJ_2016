#include <stdio.h>
#include <string.h>

const int maxn = 1000 + 10;

int n, x, y, r;
int G[maxn][maxn];
bool cannotgo;
int left, right;
int add[8][2] = {
	1, 0,
	1, 1,
	0, 1,
	-1, 1,
	-1, 0,
	-1, -1,
	0, -1,
	1, -1,
};


void fillGraph(int x, int y, int r) {
	int r2 = r * r;
	for (int i = x - r; i <= x + r; i++) {
		if (i < 0 || i > 1000) continue;
		for (int j = y - r; j <= y + r; j++) {
			if (j < 0 || j > 1000) continue;
			if ((i - x) * (i - x) + (j - y) * (j - y) <= r2) {
				G[i][j] = 1;
			}
		}
	}
}

void dfs(int x, int y) {
	G[x][y] = 2;
	if (y == 0) {
		cannotgo = true;
		return;
	}
	if (x == 0) {
		left = y < left ? y : left;
	}
	if (x == 1000) {
		right = y < right ? y : right;
	}
	for (int i = 0; i < 8; i++) {
		if (G[x + add[i][0]][y + add[i][1]] == 1) {
			dfs(x + add[i][0], y + add[i][1]);
		}
	}
}

void start() {
	for (int i = 0; i <= 1000; i++) {
		if (G[i][1000] == 1) {
			dfs(i, 1000);
			if (cannotgo) return;
		}
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		memset(G, 0, sizeof(G));
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &x, &y, &r);
			fillGraph(x, y, r);
		}
		cannotgo = false;
		left = right = 0;
		start();
		if (cannotgo) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("0.00 %.2f 1000.00 %.2f\n", left, right);
		}
	}
	return 0;
}