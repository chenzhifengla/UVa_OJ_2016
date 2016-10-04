#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const char* dirs = "NESW";
const char* turns = "FLR";
int dir_id(char c) { return strchr(dirs, c) - dirs; }
int turn_id(char c) { return strchr(turns, c) - turns; }
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };
int r0, c0, dir;
int r1, c1;
int r2, c2;
int has_edge[10][10][5][5];
int d[10][10][5];

struct Node {
	int dir;
	int r, c;
	Node(int r, int c, int dir) :r(r), c(c), dir(dir) {}
};

Node walk(const Node& u, int turn) {
	int dir = u.dir;
	if (turn == 1) dir = (dir + 3) % 4;
	if (turn == 2) dir = (dir + 1) % 4;
	return Node(u.r + dr[dir], u.c + dc[dir], dir);
}

void print_ans(Node u) {
	vector<Node> nodes;
	for (;;) {
		nodes.push_back(u);
		if (d[u.r][u.c][u.dir] == 0) break;
		u = p[u.r][u.c][u.dir];
	}
	nodes.push_back(Node(r0, c0, dir));

	int cnt = 0;
	for (int i = nodes.size() - 1; i >= 0; i--) {
		if (cnt % 10 == 0) printf(" ");
		printf(" (%d,%d)", nodes[i].r, nodes[i].c);
		if (++cnt % 10 == 0) printf("\n");
	}
	if (nodes.size() % 10 != 0) printf("\n");
}
void solve() {
	queue<Node> q;
	memset(d, -1, sizeof(d));
	Node u(r1, c1, dir);
	d[u.r][u.c][u.dir] = 0;
	q.push(u);
	while (!q.empty()) {
		Node u = q.front(); q.pop();
		if (u.r == r2 && u.c == c2) {
			print_ans(u);
			return;
		}
		for (int i = 0; i < 3; i++) {
			Node v = walk(u, i);
			if (has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	printf("No Solution Possible\n");
}

