#include <cstdio>
#include <iostream>
#include <queue>
#include <string.h>
//using namespace std;

struct Point {
	int x, y;
	int step;
};

int G[8][8];
std::queue<Point> points;
Point start, end;
int ans;

int add[8][2] = {
	2, 1,
	1, 2,
	-1, 2,
	-2, 1,
	-2, -1,
	-1, -2,
	1, -2,
	2, -1
};

int main() {
	char cmd[2];
	while (scanf("%s", cmd) != EOF) {
		printf("To get from %s to ", cmd);
		start.x = cmd[0] - 'a';
		start.y = cmd[1] - '1';
		start.step = 0;
		scanf("%s", cmd);
		printf("%s takes ", cmd);
		end.x = cmd[0] - 'a';
		end.y = cmd[1] - '1'; 

		ans = 0;
		memset(G, 0, sizeof(G));
		while (!points.empty()) points.pop();

		points.push(start);
		while (!points.empty()) {
			Point t = points.front();
			points.pop();
			G[t.x][t.y] = 1;
			if (t.x == end.x && t.y == end.y) {
				ans = t.step;
				break;
			}
			for (int i = 0; i < 8; i++) {
				int x1 = t.x + add[i][0];
				int y1 = t.y + add[i][1];
				if (x1 < 0 || x1 >= 8 || y1 < 0 || y1 >= 8 || G[x1][y1] == 1) continue;
				Point p;
				p.x = x1; p.y = y1;
				p.step = t.step + 1;
				points.push(p);
			}
		}
		printf("%d knight moves.\n", ans);
	}
	return 0;
}