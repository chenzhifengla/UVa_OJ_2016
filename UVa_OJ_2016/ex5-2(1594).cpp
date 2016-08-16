#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<vector<int> > tupleSet;

bool isZero(vector<int> tuple) {
	for (int i = 0; i < tuple.size(); i++) {
		if (tuple[i] != 0) return 0;
	}
	return 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		tupleSet.clear();
		int n;
		scanf("%d", &n);
		vector<int> tuple;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			tuple.push_back(x);
		}
		tupleSet.insert(tuple);
		for (;;) {
			vector<int> newtuple;
			for (int i = 0; i < n; i++) {
				newtuple.push_back(abs(tuple[i] - tuple[(i + 1) % n]));
			}
			if (isZero(newtuple)) {
				printf("ZERO\n");
				break;
			}
			if (tupleSet.find(newtuple) != tupleSet.end()) {
				printf("LOOP\n");
				break;
			}
			tuple = newtuple;
			tupleSet.insert(tuple);
		}
	}
	return 0;
}