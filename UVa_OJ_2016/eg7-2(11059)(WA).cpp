#include <cstdio>

int buf[18];

long long max;

int main() {
	int n, cnt = 1;
	while (scanf("%d", &n) != EOF && n != 0) {
		max = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		int begin, end;
		long long ans = 1;
		for (begin = 0; begin < n; begin++) {
			for (end = begin; end < n; end++) {
				ans = 1;
				for (int i = begin; i <= end; i++) {
					ans *= buf[i];
				}
				max = ans > max ? ans : max;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", cnt, max);
	}
	return 0;
}