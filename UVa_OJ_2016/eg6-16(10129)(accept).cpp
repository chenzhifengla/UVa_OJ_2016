//#include <iostream>
//#include <string.h>
//
//const int maxn = 128;
//int n;
//int G[maxn][maxn];
//int idx[maxn];
////idx=0表示没有,idx=1表示访问过,idx=-1表示有却没访问过
//char buf[1001];
//int in[maxn], out[maxn];
//
//void dfs(int u) {
//	idx[u] = 1;
//	for (int i = 'a'; i <= 'z'; i++) {
//		if (G[u][i] > 0 && idx[i] == -1){
//			dfs(i);
//		}
//	}
//}
//
//bool isConnected() {
//	for (int i = 'a'; i <= 'z'; i++) {
//		if (idx[i] == -1) {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool isEuler() {
//	int diff[2][2];
//	int num = 0;
//	for (int i = 'a'; i <= 'z'; i++) {
//		if (in[i] != out[i]) {
//			if (num > 1) return false;
//			diff[num][0] = in[i];
//			diff[num][1] = out[i];
//			num++;
//		}
//	}
//	if (((diff[0][0] - diff[0][1] == 1) && (diff[1][1] - diff[1][0] == 1)) ||
//		((diff[0][1] - diff[0][0] == 1) && (diff[1][0] - diff[1][1] == 1))) {
//		return true;
//	}
//	return false;
//}
//
//int main() {
//	int t;
//	scanf("%d", &t);
//	while (t--) {
//		memset(G, 0, sizeof(G));
//		memset(idx, 0, sizeof(idx));
//		memset(in, 0, sizeof(in));
//		memset(out, 0, sizeof(out));
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++) {
//			scanf("%s", buf);
//			int len = strlen(buf);
//			G[buf[0]][buf[len - 1]]++;
//			idx[buf[0]] = -1;
//			in[buf[0]]++;
//			out[buf[len - 1]]++;
//		}
//		for (int i = 'a'; i <= 'z'; i++) {
//			if (idx[i] == -1) {
//				dfs(i);
//				break;
//			}
//		}
//		if (isConnected() && isEuler()) {
//			printf("Ordering is possible\n");
//		}
//		else{
//			printf("The door cannot be opened\n");
//		}
//	}
//	return 0;
//}


// 2017-01-25-chenkuan
// 下面是用dfs直接遍历得到的结果，虽然正确但超时

//#include <iostream>
//#include <vector>
//#include <string>
//#include <set>
//#include <map>
//using namespace std;
//map<char, map<char, int>> G;
//int vis_num, edge_num;
//
//bool dfs(char c) {
//    for (auto& ch : G[c]) {
//        if (ch.second > 0) {
//            ch.second--;
//            vis_num++;
//            if (dfs(ch.first)) return true;
//            vis_num--;
//            ch.second++;
//        }
//    }
//    if (vis_num == edge_num) return true;
//    else return false;
//}
//
//int main() {
//    freopen("eg6-16(10129).in", "r", stdin);
//    int t;
//    cin >> t;
//    while (t--) {
//        G.clear();
//        int n;
//        cin >> n;
//        edge_num = n;
//        string s;
//        while (n--) {
//            cin >> s;
//            char c1 = s[0], c2 = s.back();
//            if (G.find(c1) == G.end()) {
//                G[c1] = map<char, int>();
//            }
//            if (G[c1].find(c2) == G[c1].end()) {
//                G[c1][c2] = 0;
//            }
//            G[c1][c2]++;
//        }
//        for (char c = 'a'; c <= 'z'; c++) {
//            if (G.find(c) == G.end() || G[c].find(c) == G[c].end()) continue;
//            if (G[c][c] % 2 == 1) G[c][c] = 1;
//            else G[c][c] = 2;
//        }
//
//        vis_num = 0;
//        bool has_ans = false;
//        for (auto it : G) {
//            if (dfs(it.first)) {
//                has_ans = true;
//                break;
//            }
//        }
//        if (has_ans) cout << "Ordering is possible." << endl;
//        else cout << "The door cannot be opened." << endl;
//    }
//    return 0;
//}


// 使用欧拉回路关于有向图的判定方法
// 1. 忽略方向后的无向图是连通的
// 2. 连通图的度数满足：
//   2.1. 最多只能有两个点的入度不等于出度，而且必须是期中一个点的出度恰好比入度大1，另一个的入度比出度大1

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;
vector<int> indegree, outdegree;
int n, vis_num;
vector<vector<bool>> G;
vector<bool> vis;
set<char> alphbets;

void dfs(int num) {
    vis[num] = true;
    vis_num++;
    for (int i = 0; i < 26; i++) {
        if (G[num][i] && !vis[i]) {
            dfs(i);
        }
    }
}

bool isConnected() {
    vis_num = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (G[i][j]) {
                dfs(i);
                if (vis_num < alphbets.size()) return false;
                else return true;
            }
        }
    }
}

bool isRightDegree() {
    int bigger = 0, smaller = 0;
    for (int i = 0; i < 26; i++) {
        if (indegree[i] == outdegree[i]) continue;
        else if (indegree[i] - outdegree[i] == 1) {
            bigger++;
        }
        else if (outdegree[i] - indegree[i] == 1) {
            smaller++;
        }
        else return false;
    }
    if (bigger == 1 && smaller == 1) return true;
    else if (bigger == 0 && smaller == 0) return true;
    else return false;
}

int main() {
    //freopen("eg6-16(10129).in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        indegree.assign(26, 0);
        outdegree.assign(26, 0);
        G.assign(26, vector<bool>(26, false));
        vis.assign(26, false);
        alphbets.clear();

        cin >> n;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            int c1 = s[0] - 'a', c2 = s.back() - 'a';
            outdegree[c1]++;
            indegree[c2]++;
            G[c1][c2] = true;
            G[c2][c1] = true;
            alphbets.insert(c1);
            alphbets.insert(c2);
        }
        if (isConnected() && isRightDegree()) {
            cout << "Ordering is possible." << endl;
        }
        else {
            cout << "The door cannot be opened." << endl;
        }
    }
}