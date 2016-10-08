#include <cstdio>
//#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 64 + 1;

char G[maxn][maxn];
int n;
vector<int> ans;

int getAns(int x, int y, int len, int add, int base) {
	//printf("enter (%d,%d) to (%d,%d), add=%d, base=%d\n", x + 1, y + 1, x + len, y + len, add, base);
	int colors[4];	//1->black, 0->white, -1->grey
	int half = len / 2;
	if (half == 0) return G[x][y] - '0';

	colors[0] = getAns(x, y, half, base * 1 + add, base * 5);
	colors[1] = getAns(x, y + half, half, base * 2 + add, base * 5);
	colors[2] = getAns(x + half, y, half, base * 3 + add, base * 5);
	colors[3] = getAns(x + half, y + half, half, base * 4 + add, base * 5);

	bool black = true, white = true;
	for (int i = 0; i < 4; i++) {
		if (colors[i] != 0) white = false;
		if (colors[i] != 1) black = false;
	}
	if (white) return 0;
	if (black) {
		//printf("zone (%d,%d) to (%d,%d) is black\n", x + 1, y + 1, x + len, y + len);
		return 1;
	}
	for (int i = 0; i < 4; i++) {
		if (colors[i] == 1) {
			//printf("in zone (%d,%d) to (%d,%d), the %dst is black, base=%d, add=%d\n", x + 1, y + 1, x + len, y + len, i + 1, base, add);
			ans.push_back((i + 1) * base + add);
		}
	}
	return -1;
}

void dye(int x, int y, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			G[x + i][y + j] = '*';
		}
	}
}

int main() {
	int cnt = 0;
	while (scanf("%d", &n) != EOF && n != 0) {
		ans.clear();
		if (cnt > 0) printf("\n");
		printf("Image %d\n", ++cnt);
		if (n > 0) {
			for (int i = 0; i < n; i++) {
				scanf("%s", G[i]);
			}
			getAns(0, 0, n, 0, 1);
			if (!ans.empty()) {
				sort(ans.begin(), ans.end());
				for (int i = 0; i < ans.size() - 1; i++) {
					printf("%d ", ans[i]);
				}
				printf("%d\n", ans[ans.size() - 1]);
			}
			printf("Total number of black nodes = %d\n", ans.size());
		}
		else {
			n = -n;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					G[i][j] = '.';
				}
				G[i][n] = '\0';
			}
			int num;
			while (scanf("%d", &num) != EOF && num != -1) {
				int x = 0, y = 0, len = n;
				while (num != 0) {
					int t = num % 5;
					num /= 5;
					len /= 2;
					if (t % 2 == 0) y += len;
					if (t > 2) x += len;
				}
				dye(x, y, len);
			}
			for (int i = 0; i < n; i++) {
				printf("%s\n", G[i]);
			}
		}
	}
	return 0;
}