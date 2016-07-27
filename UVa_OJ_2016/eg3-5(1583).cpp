//
// Created by chenkuaan on 7/27/16.
//

#include <cstdio>
#include <cstring>
#define maxn 100005
int ans[maxn];

int main(){
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i < maxn; i++){
        int x = i, y = i;
        while (x > 0){
            y += x % 10;
            x /= 10;
        }
        if (ans[y] == 0 || i < ans[y]) {
            ans[y] = i;
        }
    }
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}