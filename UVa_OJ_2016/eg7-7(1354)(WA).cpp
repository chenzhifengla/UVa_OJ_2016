// 2017-02-02-chenkuan

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
double r;
int s;
struct Node {
    int weight;
    double llen, rlen;
    Node(int w = 0, double l = 0, double r = 0) :weight(w), llen(l), rlen(r) {}
    bool operator < (const Node& b) const {
        if (weight != b.weight) return weight < b.weight;
        else if (llen != b.llen) return llen < b.llen;
        else return rlen < b.rlen;
    }
};
double max_width;

void dfs(map<Node, int> nodes) {
    if (nodes.size() == 1 && nodes.begin()->second == 1) {
        Node node = nodes.begin()->first;
        max_width = max(max_width, node.llen + node.rlen);
        return;
    }
    for (auto it1 = nodes.begin(); it1 != nodes.end(); it1++) {
        Node node1 = it1->first;
        for (auto it2 = nodes.begin(); it2 != nodes.end(); it2++) {
            if (it1 == it2 && it1->second <= 1) continue;
            Node node2 = it2->first;
            Node noden;
            noden.weight = node1.weight + node2.weight;
            noden.llen = node1.llen + (double)node2.weight / (double)(noden.weight);
            noden.rlen = node2.rlen + (double)node1.weight / (double)(noden.weight);
            if (noden.llen + noden.rlen < r) {
                map<Node, int> nodesn = nodes;
                if (nodesn.find(noden) == nodesn.end()) nodesn[noden] = 1;
                else nodesn[noden]++;
                if ((--nodesn[node1]) == 0) nodesn.erase(node1);
                if ((--nodesn[node2]) == 0) nodesn.erase(node2);
                dfs(nodesn);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("eg7-7(1354).in", "r", stdin);
#endif // LOCAL

    int t;
    cin >> t;
    while (t--) {
        cin >> r >> s;
        map<Node, int> nodes;
        nodes.clear();
        for (int i = 0; i < s; i++) {
            Node node;
            cin >> node.weight;
            if (nodes.find(node) == nodes.end()) nodes[node] = 1;
            else nodes[node]++;
        }
        max_width = 0;
        dfs(nodes);
        if (max_width) {
            printf("%.16lf\n", max_width);
        }
        else cout << "-1" << endl;
    }
    return 0;
}