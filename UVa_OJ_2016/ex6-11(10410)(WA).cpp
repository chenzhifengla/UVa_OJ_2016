#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int val;
	vector<int> sons;
	bool operator < (const Node& b) const {
		return val < b.val;
	}
};
vector<Node> nodes;

struct Level {
	int left;
	int right;
	int now;
	//int len;
};
vector<Level> levels;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		nodes.clear();
		levels.clear();

		int num;
		Node node;
		for (int i = 0; i < n; i++) {
			scanf("%d", &num);
			node.val = num;
			nodes.push_back(node);
		}

		int index;
		for (index = 0; index < n; index++) {
			scanf("%d", &num);
			if (levels.empty()) {
				Level level;
				level.left = 0;
				level.now = 0;
				levels.push_back(level);
				continue;
			}
			bool find = false;
			for (int i = levels.back().left + 1; i < n; i++) {
				if (nodes[i].val == num) {
					levels[levels.size() - 1].right = i;
					nodes[levels[levels.size() - 1].left].sons.push_back(nodes[i].val);
					Level level;
					level.left = i;
					level.now = i;
					levels.push_back(level);
					find = true;
					break;
				}
			}
			if (!find) {
				levels[levels.size() - 1].right = n;
				break;
			}
		}
		/*printf("levels:\n");
		for (int i = 0; i < levels.size(); i++) {
			printf("left=%d,right=%d,now=%d\n", levels[i].left, levels[i].right, levels[i].now);
		}*/
		
		for (;; index++) {
			//printf("this value is %d, index=%d\n", num, index);
			for (int lindex = 0; lindex < levels.size(); lindex++) {
				
				if (levels[lindex].right - levels[lindex].now == 1) continue;
				if (nodes[levels[lindex].now + 1].val == num) {
					//printf("push %d to BFS index %d\n", num, levels[lindex].now + 1);
					levels[lindex].now++;
					nodes[levels[lindex - 1].now].sons.push_back(nodes[levels[lindex].now].val);
				}
			}
			if (index == n - 1) break;
			scanf("%d", &num);
		}
		/*printf("levels:\n");
		for (int i = 0; i < levels.size(); i++) {
			printf("left=%d,right=%d,now=%d\n", levels[i].left, levels[i].right, levels[i].now);
		}*/


		sort(nodes.begin(), nodes.end());
		for (int i = 0; i < n; i++) {
			printf("%d:", nodes[i].val);
			for (int j = 0; j < nodes[i].sons.size(); j++) {
				printf(" %d", nodes[i].sons[j]);
			}
			printf("\n");
		}
	}
	return 0;
}