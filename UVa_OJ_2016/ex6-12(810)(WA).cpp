#include <cstdio>
#include <cstring>
#include <deque>

const int maxn = 10 + 2;

int G[maxn][maxn];
int flag[maxn][maxn];
int r, c;
int xs, ys;
int top, face, right;
int neibor[7][7] = {
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 4, 2, 5, 3, 0,
	0, 3, 0, 6, 1, 0, 4,
	0, 5, 1, 0, 0, 6, 2,
	0, 2, 6, 0, 0, 1, 5,
	0, 4, 0, 1, 6, 0, 3,
	0, 0, 3, 5, 2, 4, 0,
};
int add[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1,
};

struct Point { int x, y; };
std::deque<Point> ans;

bool dfs(int x, int y) {
	flag[x][y] = 1;
	Point p;
	p.x = x; p.y = y;
	ans.push_back(p);

	printf("enter Point(%d,%d)\n  ", x, y);
	for (int i = 0; i < ans.size(); i++) {
		printf("(%d,%d)->", ans[i].x, ans[i].y);
	}
	printf("\n");

	for (int i = 0; i < 4; i++) {
		int x1 = x + add[i][0];
		int y1 = y + add[i][1];
		if (x1 < 1 || x1 > r || y1 < 1 || y1 > c) continue;
		if (G[x1][y1] == -1 || G[x1][y1] == top) {
			if (x1 == xs && y1 == ys) {
				Point p;
				p.x = x1;
				p.y = y1;
				ans.push_back(p);
				return true;
			}
			if (flag[x1][y1] == 1) continue;

			int top_b = top, face_b = face, right_b = right;
			if (i == 0) { int t = top; top = 7 - face; face = t; }
			else if (i == 1) { int t = face; face = 7 - top; top = t; }
			else if (i == 2) { top = 7 - right; right = neibor[top][face]; }
			else if (i == 3) { top = right; right = neibor[top][face]; }
			if (dfs(x1, y1)) return true;
			top = top_b; face = face_b; right = right_b;
		}
	}
	flag[x][y] = 0;
	ans.pop_back();
	return false;
}

int main() {
	char head[20];
	while (scanf("%s", head) != EOF && strcmp(head, "END") != 0) {
		memset(G, 0, sizeof(G));
		memset(flag, 0, sizeof(flag));
		ans.clear();
		scanf("%d%d%d%d%d%d", &r, &c, &xs, &ys, &top, &face);
		right = neibor[top][face];
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				scanf("%d", &G[i][j]);
			}
		}
		printf("%s", head);
		if (!dfs(xs, ys)) {
			printf("\n  No Solution Possible\n");
		}
		else {
			for (int i = 0; !ans.empty(); i++) {
				if (i % 9 == 0) printf("\n  ");
				printf("(%d,%d)", ans.front().x, ans.front().y);
				ans.pop_front();
				if (!ans.empty()) {
					printf(",");
				}
			}
			printf("\n");
		}

	}
	return 0;
}