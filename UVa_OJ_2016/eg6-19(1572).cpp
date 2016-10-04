#include <cstdio>
#include <string.h>

int n;
int G[52][52];
int flag[52];
//flag=0表示没有访问过,flag=1表示已经访问过,flag=-1表示正在访问中

bool dfs(int u) {
	flag[u] = -1;
	for (int v = 0; v < 52; v++) {
		if (G[u][v]) {
			if (flag[v] < 0) return false;
			else if (!flag[v] && !dfs(v)) return false;
		}
	}
	flag[u] = 1;
	return true;
}

int main() {
	while (scanf("%d", &n) != EOF && n != 0) {
		memset(G, 0, sizeof(G));
		char cmd[10];
		for (int i = 0; i < n; i++) {
			scanf("%s", cmd);
			int node[4];
			for (int i = 0; i < 4; i++) {
				if (cmd[i * 2] == '0') {
					node[i] = -1;
					continue;
				}
				node[i] = cmd[i * 2] - 'A';
				node[i] = cmd[i * 2 + 1] == '+' ? node[i] + 26 : node[i];
			}
			if (node[0] > 0 && node[2] > 0) {
				G[node[0]][node[2]] = 1;
				G[node[2]][node[0]] = 1;
			}
			if (node[1] > 0 && node[3] > 0) {
				G[node[1]][node[3]] = 1;
				G[node[3]][node[1]] = 1;
			}
		}
		memset(flag, 0, sizeof(flag));
		bool bound = true;
		for (int i = 0; i < 52; i++) {
			if (!dfs(i)) {
				bound = false;
				break;
			}
		}
		if (bound) {
			printf("bounded\n");
		}
		else printf("unbounded\n");
	}
	return 0;
}