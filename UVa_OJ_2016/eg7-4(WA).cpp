#include <stdio.h>

int n;
int A[21];
int vis[21] = { 0 };
int isp[21] = { 0 };

void dfs(int cur) {
	if (cur == n && isp[A[0] + A[n - 1]]) {
		for (int i = 0; i < n - 1; i++) printf("%d ", A[i]);
		printf("%d\n", A[n - 1]);
	}
	else for (int i = 2; i <= n; i++) {
		if (!vis[i] && isp[i + A[cur - 1]]) {
			A[cur] = i;
			vis[i] = 1;
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 21; i++) {
		A[i] = i + 1;
		isp[i] = 1;
	}
	for (int i = 2; i < 21; i++) {
		for (int j = 2; j <= i; j++) {
			if (i * j < 21 && isp[j] == 1) {
				isp[i * j] = 0;
			}
		}
	}
	int cnt = 0;
	while (scanf("%d", &n) != EOF) {
		if (cnt) printf("\n");
		printf("Case %d:\n", ++cnt);
		A[0] = 1;
		dfs(1);
	}
	return 0;
}