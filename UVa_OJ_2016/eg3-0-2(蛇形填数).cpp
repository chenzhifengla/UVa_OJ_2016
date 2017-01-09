//2017-01-09-chenkuan

#include <stdio.h>
#include <memory.h>
#define maxn 10
int buf[maxn][maxn];
int n;

int main() {
    while (scanf("%d", &n) != EOF) {
        memset(buf, 0, sizeof(buf));
        int x = 0, y = n - 1;
        buf[x][y] = 1;
        int num = 1;
        while (num < n * n) {
            while (x + 1 < n && !buf[x + 1][y]) {
                buf[++x][y] = ++num;
            }
            while (y - 1 >= 0 && !buf[x][y - 1]) {
                buf[x][--y] = ++num;
            }
            while (x - 1 >= 0 && !buf[x - 1][y]) {
                buf[--x][y] = ++num;
            }
            while (y + 1 < n && !buf[x][y + 1]) {
                buf[x][++y] = ++num;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%3d", buf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}