//
// Created by chenkuaan on 7/27/16.
//

#include <cstdio>
#define maxlen 1010

int main(){
    int n, a[maxlen], b[maxlen], gamecase = 0;
    while (scanf("%d", &n) != EOF && n){
        printf("Game %d:\n", ++gamecase);
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        while (true){
            int A = 0, B = 0;
            for (int i = 0; i < n; i++){
                scanf("%d", &b[i]);
                if (b[i] == a[i]) A++;
            }
            if (b[0] == 0) break;
            int c1[10] = {0}, c2[10] = {0};
            for (int i = 0; i < n; i++){
                c1[a[i]]++;
                c2[b[i]]++;
            }
            for (int i = 1; i < 10; i++){
                B += c1[i] > c2[i] ? c2[i] : c1[i];
            }
            printf("    (%d,%d)\n", A, B-A);
        }
    }
    return 0;
}