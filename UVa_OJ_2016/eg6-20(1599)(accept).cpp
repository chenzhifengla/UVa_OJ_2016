// 2017-01-29-chenkuan

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <deque>
using namespace std;
vector<vector<int>> G;
vector<int> dist;
vector<bool> vis;   // 0表示未访问过，1表示访问过，2表示在队列中正在访问
struct Edge {
    int a, b, color;
    Edge(int a = 0, int b = 0, int color = 0) :a(a), b(b), color(color) {}
};
vector<Edge> edges;

int main() {
#ifdef LOCAL
    freopen("eg6-20(1599).in", "r", stdin);
#endif // LOCAL

    int n, m;
    while (cin >> n >> m) {
        G.assign(n + 1, vector<int>());
        edges.clear();
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            edges.emplace_back(a, b, c);
            G[a].push_back(edges.size() - 1);
            edges.emplace_back(b, a, c);
            G[b].push_back(edges.size() - 1);
        }

        dist.assign(n + 1, 0);
        vis.assign(n + 1, false);
        queue<int> Q_dist;
        Q_dist.push(n);
        vis[n] = true;
        while (!Q_dist.empty()) {
            int node = Q_dist.front();
            Q_dist.pop();
            for (auto edge_index : G[node]) {
                int node_next = edges[edge_index].b;
                if (vis[node_next] == false) {
                    vis[node_next] = true;
                    dist[node_next] = dist[node] + 1;
                    Q_dist.push(node_next);
                }
            }
        }
        cout << dist[1] << endl;

        vector<int> Q_dict;
        Q_dict.push_back(1);
        vis.assign(n + 1, 0);
        vis[1] = true;
        vector<int> ans;
        for (int i = 0; i < dist[1]; i++) {
            int shortest_color = INT_MAX;
            for (auto node : Q_dict) {
                for (auto edge_index : G[node]) {
                    int node_next = edges[edge_index].b;
                    if (dist[node] == dist[node_next] + 1 && edges[edge_index].color < shortest_color) {
                        shortest_color = edges[edge_index].color;
                    }
                }
            }
            ans.push_back(shortest_color);
            vector<int> Q_dict_new;
            for (auto node : Q_dict) {
                for (auto edge_index : G[node]) {
                    int node_next = edges[edge_index].b;
                    if (dist[node] == dist[node_next] + 1 && edges[edge_index].color == shortest_color &&
                        vis[node_next] == false) {
                        vis[node_next] = true;
                        Q_dict_new.push_back(node_next);
                    }
                }
            }
            Q_dict = Q_dict_new;
        }
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++) {
            cout << ' ' << ans[i];
        }
        cout << endl;
    }
    return 0;
}