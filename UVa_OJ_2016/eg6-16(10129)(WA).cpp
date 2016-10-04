#include <iostream>
#include <string.h>

const int maxn = 128;
int n;
int G[maxn][maxn];
int idx[maxn];
//idx=0表示没有,idx=1表示访问过,idx=-1表示有却没访问过
char buf[1001];
int in[maxn], out[maxn];

void dfs(int u) {
	idx[u] = 1;
	for (int i = 'a'; i <= 'z'; i++) {
		if (G[u][i] > 0 && idx[i] == -1){
			dfs(i);
		}
	}
}

bool isConnected() {
	for (int i = 'a'; i <= 'z'; i++) {
		if (idx[i] == -1) {
			return false;
		}
	}
	return true;
}

bool isEuler() {
	int diff[2][2];
	int num = 0;
	for (int i = 'a'; i <= 'z'; i++) {
		if (in[i] != out[i]) {
			if (num > 1) return false;
			diff[num][0] = in[i];
			diff[num][1] = out[i];
			num++;
		}
	}
	if (((diff[0][0] - diff[0][1] == 1) && (diff[1][1] - diff[1][0] == 1)) ||
		((diff[0][1] - diff[0][0] == 1) && (diff[1][0] - diff[1][1] == 1))) {
		return true;
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(G, 0, sizeof(G));
		memset(idx, 0, sizeof(idx));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", buf);
			int len = strlen(buf);
			G[buf[0]][buf[len - 1]]++;
			idx[buf[0]] = -1;
			in[buf[0]]++;
			out[buf[len - 1]]++;
		}
		for (int i = 'a'; i <= 'z'; i++) {
			if (idx[i] == -1) {
				dfs(i);
				break;
			}
		}
		if (isConnected() && isEuler()) {
			printf("Ordering is possible\n");
		}
		else{
			printf("The door cannot be opened\n");
		}
	}
	return 0;
}