//#include <cstdio>
//#include <cstring>
//#include <queue>
//using namespace std;
//
//struct Node {
//	int v[3], dist;
//	bool operator < (const Node& rhs) const {
//		return dist > rhs.dist;
//	}
//};
//
//const int maxn = 200 + 5;
//int vis[maxn][maxn], cap[3], ans[maxn];
//
//void update_ans(const Node& u) {
//	for (int i = 0; i < 3; i++) {
//		int d = u.v[i];
//		if (ans[d] < 0 || u.dist < ans[d]) ans[d] = u.dist;
//	}
//}
//
//void solve(int a, int b, int c, int d) {
//	cap[0] = a; cap[1] = b; cap[2] = c;
//	memset(vis, 0, sizeof(vis));
//	memset(ans, -1, sizeof(ans));
//	priority_queue<Node> q;
//	Node start;
//	start.dist = 0;
//	start.v[0] = 0; start.v[1] = 0; start.v[2] = c;
//	q.push(start);
//
//	vis[0][0] = 1;
//	while (!q.empty()) {
//		Node u = q.top(); q.pop();
//		update_ans(u);
//		if (ans[d] >= 0) break;
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 3; j++) {
//				if (i != j) {
//					if (u.v[i] == 0 || u.v[j] == cap[j]) continue;
//					int amount = min(cap[j], u.v[i] + u.v[j]) - u.v[j];
//					Node u2;
//					memcpy(&u2, &u, sizeof(u));
//					u2.dist = u.dist + amount;
//					u2.v[i] -= amount;
//					u2.v[j] += amount;
//					if (!vis[u2.v[0]][u2.v[1]]) {
//						vis[u2.v[0]][u2.v[1]] = 1;
//						q.push(u2);
//					}
//				}
//			}
//		}
//	}
//	while (d >= 0) {
//		if (ans[d] >= 0) {
//			printf("%d %d\n", ans[d], d);
//			return;
//		}
//		d--;
//	}
//}
//
//int main() {
//	int T, a, b, c, d;
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d%d%d%d", &a, &b, &c, &d);
//		solve(a, b, c, d);
//	}
//	return 0;
//}


// 2017-02-03-chenkuan

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 200 + 5;
vector<vector<bool>> vis;
vector<int> ans;
struct Node {
    vector<int> cap;
    int dist;
    Node() {
        cap.assign(3, 0);
        dist = 0;
    }
    bool operator < (const Node& b) const {
        return dist > b.dist;
    }
};

int main() {
#ifdef LOCAL
    freopen("eg7-8(10603).in", "r", stdin);
#endif // LOCAL

    int t, a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        vector<int> cap{ a, b, c };
        vis.assign(maxn, vector<bool>(maxn, false));
        ans.assign(maxn, -1);

        Node start;
        start.cap[2] = c;
        priority_queue<Node> Q;
        Q.push(start);
        vis[0][0] = true;

        while (!Q.empty()) {
            Node node = Q.top();
            Q.pop();
            for (auto cc : node.cap) {
                if (ans[cc] < 0 || node.dist < ans[cc]) {
                    ans[cc] = node.dist;
                }
            }

            if (ans[d] > 0) break;
            // 把第i杯往第j杯倒
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == j) continue;   // 两杯不能相同
                    if (node.cap[i] == 0) continue; // 第i杯没水
                    if (node.cap[j] == cap[j]) continue;    // 第j杯已满
                    int amount = min(cap[j], node.cap[i] + node.cap[j]) - node.cap[j];  // 倒了多少
                    Node node2 = node;
                    node2.dist = node.dist + amount;    // 新的已倒水量
                    node2.cap[i] -= amount;
                    node2.cap[j] += amount;
                    if (vis[node2.cap[0]][node2.cap[1]] == false) {
                        vis[node2.cap[0]][node2.cap[1]] = true;
                        Q.push(node2);
                    }
                }
            }
        }

        while (d >= 0) {
            if (ans[d] >= 0) {
                cout << ans[d] << ' ' << d << endl;
                break;
            }
            d--;
        }
    }
    return 0;
}