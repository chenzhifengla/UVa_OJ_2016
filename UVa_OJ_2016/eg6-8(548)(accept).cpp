//#include<iostream>
//#include <string>
//#include<sstream>
//#include <algorithm>
//using namespace std;
//
//const int maxv = 10000 + 10;
//int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
//int n;
//
//bool read_list(int* a) {
//	string line;
//	if (!getline(cin, line)) return false;
//	stringstream ss(line);
//	n = 0;
//	int x;
//	while (ss >> x) a[n++] = x;
//	return n > 0;
//}
//
//int build(int L1, int R1, int L2, int R2) {
//	if (L1 > R1) return 0;
//	int root = post_order[R2];
//	int p = L1;
//	while (in_order[p] != root) p++;
//	int cnt = p - L1;
//	lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
//	rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
//	return root;
//}
//
//int best, best_sum;
//void dfs(int u, int sum) {
//	sum += u;
//	if (!lch[u] && !rch[u]) {
//		if (sum < best_sum || (sum == best_sum && u < best)) { best = u; best_sum = sum; }
//	}
//	if (lch[u]) dfs(lch[u], sum);
//	if (rch[u]) dfs(rch[u], sum);
//}
//
//int main() {
//	while (read_list(in_order)) {
//		read_list(post_order);
//		build(0, n - 1, 0, n - 1);
//		best_sum = 1000000000;
//		dfs(post_order[n - 1], 0);
//		cout << best << '\n';
//	}
//	return 0;
//}


// 2017-01-23-chenkuan

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
using namespace std;
vector<int> in_order, post_order;
struct Node {
    int left, right, value;
    Node(int value = 0, int left = 0, int right = 0) :left(left), right(right), value(value) {}
};
vector<Node> tree;

bool readLine(vector<int>& order) {
    string line;
    if (!getline(cin, line)) return false;
    stringstream ss(line);
    int x;
    while (ss >> x) {
        order.push_back(x);
    }
    return order.size() > 0;
}

int buildTree(int p1, int p2, int q1, int q2) {
    if (p1 >= p2 || q1 >= q2) return -1;
    Node root = Node(post_order[q2 - 1]);
    int root_index = p1;
    while (in_order[root_index] != root.value) root_index++;
    int left_tree_len = root_index - p1;
    root.left = buildTree(p1, root_index, q1, q1 + left_tree_len);
    root.right = buildTree(root_index + 1, p2, q1 + left_tree_len, q2 - 1);
    tree.push_back(root);
    return tree.size() - 1;
}

int best, best_sum;
void preOrderTraverse(int root, int sum) {
    sum += tree[root].value;
    if (tree[root].left < 0 && tree[root].right < 0) {
        if (sum < best_sum || (sum == best_sum && tree[root].value < tree[best].value)) {
            best = root;
            best_sum = sum;
        }
    }
    if (tree[root].left >= 0) preOrderTraverse(tree[root].left, sum);
    if (tree[root].right >= 0) preOrderTraverse(tree[root].right, sum);
}

int main() {
    //freopen("eg6-8(548).in", "r", stdin);
    while (readLine(in_order)) {
        readLine(post_order);
        tree.clear();
        int root = buildTree(0, in_order.size(), 0, post_order.size());
        best_sum = INT_MAX;
        preOrderTraverse(root, 0);
        cout << tree[best].value << endl;
        in_order.clear();
        post_order.clear();
    }
    return 0;
}