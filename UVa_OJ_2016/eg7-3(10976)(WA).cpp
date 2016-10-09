#include <cstdio>

int k;

int main() {
	while (scanf("%d", &k) != EOF) {
		for (int y = k + 1; y <= 2 * k; y++) {
			if ((k * y) % (y - k) == 0) {
				int x = (k * y) / (y - k);
				if (x < y) continue;
				printf("1/%d = 1/%d + 1/%d\n", k, x, y);
			}
		}
	}
	return 0;
}