//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//
//int cmp(const void *a, const void *b) {
//	return *(int*)a - *(int*)b;
//}
//
//int main() {
//	char first[110];
//	char second[110];
//	while (scanf("%s%s", first, second) != EOF) {
//		int cnt1[26] = { 0 }, cnt2[26] = { 0 };
//		for (int i = 0; i < strlen(first); i++) {
//			cnt1[first[i] - 'A']++;
//		}
//		for (int i = 0; i < strlen(second); i++) {
//			cnt2[second[i] - 'A']++;
//		}
//		qsort(cnt1, 26, sizeof(int), cmp);
//		qsort(cnt2, 26, sizeof(int), cmp);
//		bool equal = true;
//		for (int i = 0; i < 26; i++) {
//			if (cnt1[i] != cnt2[i]) {
//				equal = false;
//				break;
//			}
//		}
//		if (equal) {
//			printf("YES\n");
//		}
//		else printf("NO\n");
//	}
//	return 0;
//}


//2017-01-10-chenkuan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char buf1[110], buf2[110];
int len1, len2;
int cnt1[26], cnt2[26];

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    while (scanf("%s%s", buf1, buf2) != EOF) {
        int equal = 1;
        len1 = strlen(buf1);
        len2 = strlen(buf2);
        if (len1 != len2) {
            equal = 0;
        }
        else {
            memset(cnt1, 0, sizeof(cnt1));
            memset(cnt2, 0, sizeof(cnt2));
            for (int i = 0; i < len1; i++) {
                cnt1[buf1[i] - 'A']++;
                cnt2[buf2[i] - 'A']++;
            }
            qsort(cnt1, 26, sizeof(int), cmp);
            qsort(cnt2, 26, sizeof(int), cmp);
            for (int i = 0; i < 26; i++) {
                if (cnt1[i] != cnt2[i]) {
                    equal = 0;
                    break;
                }
            }
        }
        if (equal) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}