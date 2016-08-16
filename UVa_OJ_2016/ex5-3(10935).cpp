#include <iostream>
#include <queue>
using namespace std;
queue<int> cards;

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		while (!cards.empty()) cards.pop();
		for (int i = 1; i <= n; i++) {
			cards.push(i);
		}
		printf("Discarded cards:");
		while (cards.size() > 1) {
			printf(" %d", cards.front());
			if (cards.size() > 2) printf(",");
			cards.pop();
			int x = cards.front();
			cards.pop();
			cards.push(x);
		}
		printf("\nRemaining card: ");
		printf("%d\n", cards.front());
	}
	return 0;
}