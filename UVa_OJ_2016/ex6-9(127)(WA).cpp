#include <cstdio>
#include <stack>
using namespace std;

struct Card {
	char value, suit;
};

struct Pile {
	stack<Card> pile;
	int last, next;
}piles[54];

int main() {
	char input[2];
	while (scanf("%s", input) != EOF && input[0] != '#') {
		for (int i = 0; i <= 53; i++) {
			while (!piles[i].pile.empty()) piles[i].pile.pop();
			piles[i].last = i - 1;
			piles[i].next = i + 1;
		}
		piles[0].last = 0;
		piles[53].next = 53;

		Card card;
		card.value = input[0];
		card.suit = input[1];
		piles[1].pile.push(card);

		for (int i = 2; i <= 52; i++) {
			scanf("%s", input);
			card.value = input[0];
			card.suit = input[1];
			piles[i].pile.push(card);
		}

		int sum = 52;

		while (1) {
			bool move = false;
			int index = piles[0].next;
			for (; index < 53; index = piles[index].next) {
				Card indexcard = piles[index].pile.top();
				int last3 = piles[piles[piles[index].last].last].last;
				if (last3 != 0) {
					Card last3card = piles[last3].pile.top();
					if (last3card.value == indexcard.value || last3card.suit == indexcard.suit) {
						//printf("move %dst card piles top card (%c%c) to %dst card pile\n", index, piles[index].pile.top().value, piles[index].pile.top().suit, last3);
						piles[last3].pile.push(piles[index].pile.top());
						piles[index].pile.pop();
						if (piles[index].pile.empty()) {
							int last = piles[index].last;
							int next = piles[index].next;
							piles[last].next = next;
							piles[next].last = last;
							sum--;
						}
						move = true;
						break;
					}
				}
				int last = piles[index].last;
				if (last != 0) {
					Card lastcard = piles[last].pile.top();
					if (lastcard.value == indexcard.value || lastcard.suit == indexcard.suit) {
						//printf("move %dst card piles top card (%c%c) to %dst card pile\n", index, piles[index].pile.top().value, piles[index].pile.top().suit, last);
						piles[last].pile.push(piles[index].pile.top());
						piles[index].pile.pop();
						if (piles[index].pile.empty()) {
							int next = piles[index].next;
							piles[last].next = next;
							piles[next].last = last;
							sum--;
						}
						move = true;
						break;
					}
				}
			}
			if (!move) break;
		}
		printf("%d piles remaining:", sum);
		for (int i = 1; i <= 52; i++) {
			if (!piles[i].pile.empty()) {
				printf(" %d", piles[i].pile.size());
			}
		}
		printf("\n");
	}
	return 0;
}