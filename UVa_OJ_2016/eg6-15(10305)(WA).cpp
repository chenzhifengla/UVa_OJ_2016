#include <iostream>
#include <string.h>

const int maxn = 101;

int n, m;
int c[maxn];
//c[u]=0��ʾ����û�з��ʹ���c[u]=1��ʾ�Ѿ����ʹ������һ��ݹ���ʹ�������������
//c[u]=-1��ʾ���ڷ�����
int topo[maxn], t;
int G[maxn][maxn];

bool dfs(int u) {
	c[u] = -1;
	for (int v = 1; v <= n; v++) {
		if (G[u][v]) {
			if (c[v] < 0) return false;
			else if (!c[v] && !dfs(v)) return false;
		}
	}
	c[u] = 1;
	topo[--t] = u;
	return true;
}

bool toposort() {
	t = n;
	memset(c, 0, sizeof(c));
	for (int u = 1; u <= n; u++) {
		if (!c[u]) {
			if (!dfs(u)) return false;
		}
	}
	return true;
}

int main() {
	while (scanf("%d%d", &n, &m) && n != 0 && m != 0) {
		memset(G, 0, sizeof(G));
		memset(topo, 0, sizeof(topo));
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			G[a][b] = 1;
		}
		toposort();
		for (int i = 0; i < n - 1; i++) {
			printf("%d ", topo[i]);
		}
		printf("%d\n", topo[n - 1]);
	}
	return 0;
}