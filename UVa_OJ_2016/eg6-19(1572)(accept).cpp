//#include <cstdio>
//#include <string.h>
//
//int n;
//int G[52][52];
//int flag[52];
////flag=0表示没有访问过,flag=1表示已经访问过,flag=-1表示正在访问中
//
//bool dfs(int u) {
//	flag[u] = -1;
//	for (int v = 0; v < 52; v++) {
//		if (G[u][v]) {
//			if (flag[v] < 0) return false;
//			else if (!flag[v] && !dfs(v)) return false;
//		}
//	}
//	flag[u] = 1;
//	return true;
//}
//
//int main() {
//	while (scanf("%d", &n) != EOF && n != 0) {
//		memset(G, 0, sizeof(G));
//		char cmd[10];
//		for (int i = 0; i < n; i++) {
//			scanf("%s", cmd);
//			int node[4];
//			for (int i = 0; i < 4; i++) {
//				if (cmd[i * 2] == '0') {
//					node[i] = -1;
//					continue;
//				}
//				node[i] = cmd[i * 2] - 'A';
//				node[i] = cmd[i * 2 + 1] == '+' ? node[i] + 26 : node[i];
//			}
//			if (node[0] > 0 && node[2] > 0) {
//				G[node[0]][node[2]] = 1;
//				G[node[2]][node[0]] = 1;
//			}
//			if (node[1] > 0 && node[3] > 0) {
//				G[node[1]][node[3]] = 1;
//				G[node[3]][node[1]] = 1;
//			}
//		}
//		memset(flag, 0, sizeof(flag));
//		bool bound = true;
//		for (int i = 0; i < 52; i++) {
//			if (!dfs(i)) {
//				bound = false;
//				break;
//			}
//		}
//		if (bound) {
//			printf("bounded\n");
//		}
//		else printf("unbounded\n");
//	}
//	return 0;
//}


// 2017-01-29-chenkuan

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<bool>> G;
vector<int> vis;    //0表示未访问过，1表示已经访问过，-1表示正在访问中

bool dfs(int node) {
    vis[node] = -1;
    for (int i = 0; i < 52; i++) {
        if (G[node][i]) {
            int node_new = (i + 26) % 52;
            if (vis[node_new] == -1) return false;
            else if (vis[node_new] == 0 && !dfs(node_new)) return false;
        }
    }
    vis[node] = 1;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("eg6-19(1572).in", "r", stdin);
#endif // LOCAL

    int n;
    while (cin >> n && n) {
        G.assign(52, vector<bool>(52, false));
        vis.assign(52, 0);
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            int pos[4];
            for (int j = 0; j < 4; j++) {
                if (s[j * 2] == '0') pos[j] = -1;
                else {
                    pos[j] = s[j * 2] - 'A';
                    if (s[j * 2 + 1] == '-') pos[j] += 26;
                }
            }
            for (int j = 0; j < 4; j++) {
                if (pos[j] < 0) continue;
                for (int k = 0; k < 4; k++) {
                    if (pos[k] < 0 || k == j) continue;
                    G[pos[j]][pos[k]] = true;
                }
            }
            //if (pos[0] >= 0 && pos[2] >= 0) G[pos[0]][pos[2]] = G[pos[2]][pos[0]] = true;
            //if (pos[1] >= 0 && pos[3] >= 0) G[pos[1]][pos[3]] = G[pos[3]][pos[1]] = true;
        }
        bool has_ring = false;
        for (int i = 0; i < 52; i++) {
            if (vis[i] == 0) {
                if (dfs(i) == false) {
                    has_ring = true;
                    break;
                }
            }
        }
        if (has_ring) cout << "unbounded" << endl;
        else cout << "bounded" << endl;
    }
    return 0;
}