//
// Created by chenkuaan on 7/27/16.
//

#include <cstdio>
#include <cstring>

#define maxn 10010

int times[maxn][10];

int main(){
    memset(times, 0, sizeof(times));
    for (int i = 1; i < maxn; i++){
        for (int j = 0; j < 10; j++){
            times[i][j] = times[i-1][j];
        }
        int num = i;
        while (num){
            times[i][num % 10]++;
            num /= 10;
        }
    }

    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 9; i++) {
            printf("%d ", times[n][i]);
        }
        printf("%d\n", times[n][9]);
    }
    return 0;
}