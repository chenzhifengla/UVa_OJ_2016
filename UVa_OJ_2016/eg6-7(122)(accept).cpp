//#include <cstdio>
//#include <cstring>
//#include <vector>
//#include <queue>
//using namespace std;
//
//const int maxn = 256;
//char s[maxn];
//
//struct Node {
//	bool have_value;
//	int v;
//	Node *left, *right;
//	Node() :have_value(false), left(NULL), right(NULL) {}
//};
//
//Node* root;
//
//Node* newnode() { return new Node(); }
//
//void addnode(int v, char* s) {
//	int n = strlen(s);
//	Node* u = root;
//	for (int i = 0; i < n; i++) {
//		if (s[i] == 'L') {
//			if (u->left == NULL) u->left = newnode();
//			u = u->left;
//		}
//		else if (s[i] == 'R') {
//			if (u->right == NULL) u->right = newnode();
//			u = u->right;
//		}
//	}
//	if (u->have_value) failed = true;
//	u->v = v;
//	u->have_value = true;
//}
//
//bool read_input() {
//	failed = false;
//	root = newnode();
//	for (;;) {
//		if (scanf("%s", s) != 1) return false;
//		if (!strcmp(s, "()")) break;
//		int v;
//		sscanf(&s[1], "%d", &v);
//		addnode(v, strchr(s, ',') + 1);
//	}
//	return true;
//}
//
//bool bfs(vector<int>& ans) {
//	queue<Node*> q;
//	ans.clear();
//	q.push(root);
//	while (!q.empty()) {
//		Node* u = q.front(); q.pop();
//		if (!u->have_value) return false;
//		ans.push_back(u->v);
//		if (u->left != NULL) q.push(u->left);
//		if (u->right != NULL) q.push(u->right);
//	}
//	return false;
//}
//
//void remove_tree(Node* u) {
//	if (u == NULL) return;
//	remove_tree(u->left);
//	remove_tree(u->right);
//	delete u;
//}


// 2017-01-23-chenkuan

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int left, right;
    int value;
    bool has_value;
    Node() { left = right = value = 0; has_value = false; };
};
vector<Node> tree;
int root;

int createNode() {
    tree.push_back(Node());
    return tree.size() - 1;
}

bool addNode(int value, string path) {
    int node = root, t;
    for (auto c : path) {
        if (c == 'L') {
            if (tree[node].left == 0) {
                t = createNode();
                tree[node].left = t;
                //tree[node].left = createNode();
            }
            node = tree[node].left;
        }
        else if (c == 'R') {
            if (tree[node].right == 0) {
                t = createNode();
                tree[node].right = t;
                //tree[node].right = createNode();
            }
            node = tree[node].right;
        }
    }
    if (tree[node].has_value) return false;
    tree[node].value = value;    tree[node].has_value = true;
    return true;
}
int main() {
    freopen("eg6-7(122).in", "r", stdin);
    string s;
    while (cin >> s) {
        tree.clear();
        root = createNode();
        bool failed = false;
        while (s != "()") {
            int index_comma = s.find(',');
            int value;
            if (index_comma - 1 <= 0) value = 0;
            else value = stoi(s.substr(1, index_comma - 1));
            string path;
            if (s.size() - index_comma - 2 <= 0) path = "";
            else path = s.substr(index_comma + 1, s.size() - index_comma - 2);
            if (addNode(value, path) == false) {
                failed = true;
            }
            cin >> s;
        }
        queue<int> Q;
        vector<int> ans;
        Q.push(root);
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            if (!tree[node].has_value) {
                failed = true;
                break;
            }
            ans.push_back(tree[node].value);
            if (tree[node].left > 0) Q.push(tree[node].left);
            if (tree[node].right > 0) Q.push(tree[node].right);
        }
        if (failed) {
            cout << "not complete" << endl;
        }
        else {
            if (!ans.empty()) {
                cout << ans[0];
                for (int i = 1; i < ans.size(); i++) {
                    cout << ' ' << ans[i];
                }
            }
            cout << endl;
        }
    }
    return 0;
}