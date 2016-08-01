#include <cstdio>

char buf[51][1001];
char ans[1001];

int main() {
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		int m, n;
		scanf("%d%d", &m, &n);
		for (int i = 0; i < m; i++) {
			scanf("%s", buf[i]);
		}
		//get ans
		for (int i = 0; i < n; i++) {
			int a = 0, c = 0, g = 0, t = 0;
			for (int j = 0; j < m; j++) {
				switch (buf[j][i]) {
				case 'A': a++; break;
				case 'C': c++; break;
				case 'G': g++; break;
				case 'T': t++; break;
				}
			}
			if (a >= c && a >= g && a >= t) {
				ans[i] = 'A';
			}
			else if (c >= g && c >= t) {
				ans[i] = 'C';
			}
			else if (g >= t) {
				ans[i] = 'G';
			}
			else ans[i] = 'T';
		}
		//get error
		int error = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (buf[j][i] != ans[i]) {
					error++;
				}
			}
		}
		//output
		for (int i = 0; i < n; i++) {
			printf("%c", ans[i]);
		}
		printf("\n%d\n", error);
	}
	return 0;
}