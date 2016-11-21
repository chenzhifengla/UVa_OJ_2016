#include <stdio.h>

int cnt, n, L;
int S[100];

int dfs(int cur) {
	if (cnt++ == n) {
		for (int i = 0; i < cur; i++) {
			printf("%c", 'A' + S[i]);
			
			if ((i + 1) % 4 == 0) printf(" ");
			if ((i + 1) % 64 == 0) printf("\n");
		}
		printf("\n%d\n", cur);
		return 0;
	}
	for (int i = 0; i < L; i++) {
		S[cur] = i;
		int ok = 1;
		for (int j = 1; j * 2 <= cur + 1; j++) {
			int equal = 1;
			for (int k = 0; k < j; k++) {
				if (S[cur - k] != S[cur - k - j]) {
					equal = 0;
					break;
				}
			}
			if (equal) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			if (!dfs(cur + 1)) return 0;
		}
	}
	return 1;
}

int main() {
	while (scanf("%d%d", &n, &L) != EOF && n != 0 && L != 0) {
		cnt = 0;
		dfs(0);
	}
	return 0;
}