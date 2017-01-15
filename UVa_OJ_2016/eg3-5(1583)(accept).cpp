//
// Created by chenkuaan on 7/27/16.
//

//#include <cstdio>
//#include <cstring>
//#define maxn 100005
//int ans[maxn];
//
//int main(){
//    memset(ans, 0, sizeof(ans));
//    for (int i = 1; i < maxn; i++){
//        int x = i, y = i;
//        while (x > 0){
//            y += x % 10;
//            x /= 10;
//        }
//        if (ans[y] == 0 || i < ans[y]) {
//            ans[y] = i;
//        }
//    }
//    int t, n;
//    scanf("%d", &t);
//    while(t--){
//        scanf("%d", &n);
//        printf("%d\n", ans[n]);
//    }
//    return 0;
//}


//2017-01-10-chenkuan

#include <stdio.h>
#include <memory.h>
#define maxn 100010
int min_buf[maxn];
int t, n;

int main() {
    memset(min_buf, 0, sizeof(min_buf));
    for (int i = 1; i <= maxn - 10; i++) {
        int j = i, sum = i;
        while (j) {
            sum += j % 10;
            j /= 10;
        }
        if (min_buf[sum] == 0 || i < min_buf[sum]) {
            min_buf[sum] = i;
        }
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", min_buf[n]);
    }
    return 0;
}