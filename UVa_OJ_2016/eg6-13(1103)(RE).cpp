#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
const int maxh = 200 + 5;
const int maxw = 50 + 5;
char buf[maxh][maxw];
int matrix[maxh][205];
int idx[maxh][205];
int h, w;
int neiboId;
bool isHole;

void dfs(int x, int y, int id) {
	if (x < 0 || x >= w || y < 0 || y >= h) return;
	if (idx[x][y] != 0 || matrix[x][y] != 1) return;
	idx[x][y] = id;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx != 0 || dy != 0) dfs(x + dx, y + dy, id);
		}
	}
}

void dfs_blank(int x, int y, int id) {
	if (x < 0 || x >= w || y < 0 || y >= h) {
		neiboId = 0;
		isHole = false;
		return;
	}
	if (idx[x][y] != 0) return;
	if (matrix[x][y] != 0) {
		if (neiboId < 0) neiboId = idx[x][y];
		else if (neiboId > 0 && neiboId != idx[x][y]) isHole = false;
		return;
	}
	idx[x][y] = id;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx != 0 || dy != 0) dfs_blank(x + dx, y + dy, id);
		}
	}
}

int main() {
	int kase = 0;
	while (scanf("%d%d", &h, &w) == 2 && h && w) {
		for (int i = 0; i < h; i++) {
			scanf("%s", buf[i]);
			for (int j = 0; j < w; j++) {
				int t = (buf[i][j] >= '0' && buf[i][j] <= '9') ? buf[i][j] - '0' : buf[i][j] - 'a' + 10;
				matrix[i][j * 4] = t / 8;	t %= 8;
				matrix[i][j * 4 + 1] = t / 4;	t %= 4;
				matrix[i][j * 4 + 2] = t / 2;	t %= 2;
				matrix[i][j * 4 + 3] = t;
			}
		}
		w *= 4;
		memset(idx, 0, sizeof(idx));
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (idx[i][j] == 0 && matrix[i][j] == 1) dfs(i, j, ++cnt);
			}
		}
		std::vector<int> holes;
		for (int i = 0; i < cnt; i++) {
			holes.push_back(0);
		}
		int area = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (idx[i][j] == 0 && matrix[i][j] == 0) {
					neiboId = -1;
					isHole = true;
					dfs_blank(i, j, --area);
					if (isHole) {
						holes[neiboId]++;
					}
				}
			}
		}
		std::vector<char> sym;
		for (int i = 0; i < holes.size(); i++) {
			if (holes[i] == 0) sym.push_back('W');
			else if (holes[i] == 1) sym.push_back('A');
			else if (holes[i] == 2) sym.push_back('K');
			else if (holes[i] == 3) sym.push_back('J');
			else if (holes[i] == 4) sym.push_back('S');
			else if (holes[i] == 5) sym.push_back('D');
		}
		sort(sym.begin(), sym.end());
		printf("Case%2d: ", ++kase);
		for (int i = 0; i < sym.size(); i++) {
			printf("%c", sym[i]);
		}
		printf("\n");
	}
	return 0;
}