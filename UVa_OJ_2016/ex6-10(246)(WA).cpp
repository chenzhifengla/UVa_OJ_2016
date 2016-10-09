#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <set>
using namespace std;

vector<deque<int> > piles;
queue<int> cards;
set<vector<deque<int> > > states;

bool isWin() {
	for (int i = 0; i < 7; i++) {
		if (!piles[i].empty()) return false;
	}
	return true;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		while (!cards.empty()) cards.pop();
		piles.clear();
		for (int i = 0; i < 7; i++) {
			deque<int> d;
			piles.push_back(d);
		}
		cards.push(n);
		for (int i = 1; i < 52; i++) {
			scanf("%d", &n);
			cards.push(n);
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 7; j++) {
				piles[j].push_back(cards.front());
				cards.pop();
			}
		}
		bool win = false, loss = false, draw = false;
		int step = 0;
		while (1) {
			if (isWin()) {
				win = true;
				break;
			}

			for (int i = 0; i < 7; i++) {
				if (cards.empty()) {
					loss = true;
					break;
				}

				if (piles[i].size() == 0) continue;
				piles[i].push_back(cards.front());
				cards.pop();
				step++;
				if (states.count(piles) == 0) {
					states.insert(piles);
				}
				else {
					draw = true;
					break;
				}
				
				while (1) {
					int size = piles[i].size();
					if (size < 3) break;

					int sum = piles[i][0] + piles[i][1] + piles[i][size - 1];
					if (sum == 10 || sum == 20 || sum == 30) {
						cards.push(piles[i][0]);
						cards.push(piles[i][1]);
						cards.push(piles[i][size - 1]);
						piles[i].pop_front();
						piles[i].pop_front();
						piles[i].pop_back();
						continue;
					}

					sum = piles[i][0] + piles[i][size - 2] + piles[i][size - 1];
					if (sum == 10 || sum == 20 || sum == 30) {
						cards.push(piles[i][0]);
						cards.push(piles[i][size - 2]);
						cards.push(piles[i][size - 1]);
						piles[i].pop_front();
						piles[i].pop_back();
						piles[i].pop_back();
						continue;
					}

					sum = piles[i][size - 1] + piles[i][size - 2] + piles[i][size - 3];
					if (sum == 10 || sum == 20 || sum == 30) {
						cards.push(piles[i][size - 3]);
						cards.push(piles[i][size - 2]);
						cards.push(piles[i][size - 1]);
						piles[i].pop_back();
						piles[i].pop_back();
						piles[i].pop_back();
						continue;
					}
					else break;
				}
			}
			if (loss) break;
			if (draw) break;
		}
		if (win) printf("Win : ");
		if (loss) printf("Loss : ");
		if (draw) printf("Draw : ");
		printf("%d\n", step);
	}
	return 0;
}