//2017-01-09-chenkuan

#include <stdio.h>
#include <memory.h>
#define maxn 1010
int buf[maxn];
int k, n;

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        memset(buf, 0, sizeof(n));
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                if (j % i == 0) {
                    buf[j] = !buf[j];
                }
            }
        }
        int first = 1;
        for (int i = 1; i <= n; i++) {
            if (buf[i]) {
                if (first) {
                    first = 0;
                }
                else {
                    printf(" ");
                }
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}