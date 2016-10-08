#include <cstdio>

const int maxn = 20 + 1;

int G[maxn][maxn];
int flag[maxn][maxn];
int m, n, k;
int stepAns;

int add[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1,
};

void dfs(int x, int y, int step, int depth) {
	flag[x][y] = 1;
	if (G[x][y] == 1) step++;
	else step = 0;
	if (x == m - 1 && y == n - 1) {
		if (stepAns == -1) stepAns = depth;
		else stepAns = depth < stepAns ? depth : stepAns;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int x1 = x + add[i][0];
			int y1 = y + add[i][1];
			if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) continue;
			if (flag[x1][y1] == 1) continue;
			if (G[x1][y1] == 1 && step + 1 > k) continue;
			dfs(x1, y1, step, depth + 1);
		}
	}
	flag[x][y] = 0;
}

int main() {
	int num;
	scanf("%d", &num);
	while (num--) {
		scanf("%d%d%d", &m, &n, &k);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &G[i][j]);
				flag[i][j] = 0;
			}
		}
		stepAns = -1;
		dfs(0, 0, 0, 0);
		printf("%d\n", stepAns);
	}
	return 0;
}