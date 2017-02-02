// 2017-02-02-chenkuan

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <climits>
using namespace std;
map<char, map<char, bool>> G;
int min_bw;
string min_ans;
string ans;

void dfs(int band_width) {
    if (ans.size() == G.size()) {
        if (band_width < min_bw || (band_width == min_bw && ans < min_ans)) {
            min_ans = ans;
            min_bw = band_width;
        }
        return;
    }
    for (auto c : G) {
        if (ans.find(c.first) != string::npos) continue;
        map<char, bool> next_nodes = c.second;
        bool ok = true;
        int next_node_num = next_nodes.size();
        for (auto next_node : next_nodes) {
            auto index = ans.find(next_node.first);
            if (index == string::npos) continue;
            next_node_num--;
            int dist = ans.size() - index;
            if (dist >= min_bw) {
                ok = false;
                break;
            }
            if (dist >= band_width) band_width = dist;
        }
        if (!ok) continue;
        if (next_node_num > min_bw) continue;
        ans.push_back(c.first);
        dfs(band_width);
        ans.pop_back();
    }
}

int main() {
#ifdef LOCAL
    freopen("eg7-6(140).in", "r", stdin);
#endif // LOCAL

    string s;
    while (cin >> s && s != "#") {
        G.clear();
        ans.clear();

        replace(s.begin(), s.end(), ';', ' ');
        replace(s.begin(), s.end(), ':', ' ');
        stringstream ss(s);
        string node, next_nodes;
        while (ss >> node) {
            char c = node[0];
            ss >> next_nodes;
            if (G.find(c) == G.end()) G[c] = map<char, bool>();
            for (auto next_node : next_nodes) {
                if (G[c].find(next_node) == G[c].end()) {
                    G[c][next_node] = true;
                }
                else G[c][next_node] = true;
                if (G.find(next_node) == G.end()) G[next_node] = map<char, bool>();
                if (G[next_node].find(c) == G[next_node].end()) {
                    G[next_node][c] = true;
                }
                else G[next_node][c] = true;
            }
        }
        min_bw = INT_MAX;
        dfs(0);
        for (auto c : min_ans) {
            cout << c << ' ';
        }
        cout << "-> " << min_bw << endl;
    }
    return 0;
}