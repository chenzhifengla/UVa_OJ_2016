#include <iostream>
#include <string>
#include <vector>
using namespace std;

string pre, in, post;
struct Node {
	char value;
	int left, right;
};
vector<Node> tree;

int buildTree(int s1, int e1, int s2, int e2) {
	if (s1 > e1) return -1;
	Node n;
	tree.push_back(n);
	int index = tree.size() - 1;
	tree[index].value = pre[s1];
	int mid = s2;
	for (; mid <= e2; mid++) {
		if (in[mid] == pre[s1]) break;
	}
	tree[index].left = buildTree(s1 + 1, s1 + mid - s2, s2, mid - 1);
	tree[index].right = buildTree(s1 + mid - s2 + 1, e1, mid + 1, e2);
	return index;
}

void postOrderTraverse(int root) {
	if (tree[root].left > 0) postOrderTraverse(tree[root].left);
	if (tree[root].right > 0) postOrderTraverse(tree[root].right);
	printf("%c", tree[root].value);
}

int main() {
	while (cin >> pre >> in) {
		tree.clear();
		buildTree(0, pre.length() - 1, 0, in.length() - 1);
		postOrderTraverse(0);
		printf("\n");
	}
	return 0;
}