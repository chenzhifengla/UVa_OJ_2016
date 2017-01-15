//#include <cstdio>
//#define maxn 25
//int n, k, m, a[maxn];
//
//int go(int p, int d, int t) {
//	while (t--) {
//		do {
//			p = (p + d + n - 1) % n + 1;
//		} while (a[p] == 0);
//	}
//	return p;
//}
//
//int main() {
//	while (scanf("%d%d%d", &n, &k, &m) == 3 && n) {
//		for (int i = 1; i <= n; i++) a[i] = i;
//		int left = n;	//还剩下的人数
//		int p1 = n, p2 = 1;
//		while (left) {
//			p1 = go(p1, 1, k);
//			p2 = go(p2, -1, m);
//			printf("%3d", p1);
//			left--;
//			if (p2 != p1) {
//				printf("%3d", p2);
//				left--;
//			}
//			a[p1] = a[p2] = 0;
//			if (left) printf(",");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//2017-01-10-chenkuan

#include <stdio.h>
#include <memory.h>
#define maxn 22
int n, k, m;
int buf[maxn];

int step(int p, int s, int t) {
    while (s--) {
        do {
            p = (p + t + n - 1) % n + 1;
        } while (buf[p] == 0);
    }
    return p;
}

int main() {
    while (scanf("%d%d%d", &n, &k, &m) != EOF && n) {
        for (int i = 1; i <= n; i++) {
            buf[i] = i;
        }
        int pos1 = n, pos2 = 1; // 放在首位的前面一位
        int left = n;
        while (left) {
            pos1 = step(pos1, k, 1);
            printf("%3d", pos1);
            left--;

            pos2 = step(pos2, m, -1);
            if (pos2 != pos1) {
                printf("%3d", pos2);
                left--;
            }
            if (left) printf(",");
            buf[pos1] = buf[pos2] = 0;
        }
        printf("\n");
    }
    return 0;
}