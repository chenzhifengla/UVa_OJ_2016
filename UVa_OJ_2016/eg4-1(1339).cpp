#include <cstdio>
#include <cstdlib>
#include <cstring>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main() {
	char first[110];
	char second[110];
	while (scanf("%s%s", first, second) != EOF) {
		int cnt1[26] = { 0 }, cnt2[26] = { 0 };
		for (int i = 0; i < strlen(first); i++) {
			cnt1[first[i] - 'A']++;
		}
		for (int i = 0; i < strlen(second); i++) {
			cnt2[second[i] - 'A']++;
		}
		qsort(cnt1, 26, sizeof(int), cmp);
		qsort(cnt2, 26, sizeof(int), cmp);
		bool equal = true;
		for (int i = 0; i < 26; i++) {
			if (cnt1[i] != cnt2[i]) {
				equal = false;
				break;
			}
		}
		if (equal) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}