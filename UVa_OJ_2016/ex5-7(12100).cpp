#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int priorityNum[10];
queue<int> print;

bool hasHigherPriority(int p) {
	for (int i = p + 1; i < 10; i++) {
		if (priorityNum[i]) return true;
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(priorityNum, 0, sizeof(priorityNum));
		while (!print.empty()) print.pop();
		int n, focus;
		scanf("%d%d", &n, &focus);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			print.push(x);
			priorityNum[x]++;
		}
		int time = 0;
		for (;;) {
			int p = print.front();
			print.pop();
			if (hasHigherPriority(p)) {
				print.push(p);
				focus--;
				if (focus < 0)	focus = n - 1;
			}
			else if (focus == 0){
				time++;
				break;
			}
			else {
				time++;
				focus--;
				n--;
				priorityNum[p]--;
			}
		}
		printf("%d\n", time);
	}
	return 0;
}