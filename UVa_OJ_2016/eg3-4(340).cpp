//
// Created by chenkuaan on 7/27/16.
//

//#include <cstdio>
//#define maxlen 1010
//
//int main(){
//    int n, a[maxlen], b[maxlen], gamecase = 0;
//    while (scanf("%d", &n) != EOF && n){
//        printf("Game %d:\n", ++gamecase);
//        for (int i = 0; i < n; i++){
//            scanf("%d", &a[i]);
//        }
//        while (true){
//            int A = 0, B = 0;
//            for (int i = 0; i < n; i++){
//                scanf("%d", &b[i]);
//                if (b[i] == a[i]) A++;
//            }
//            if (b[0] == 0) break;
//            int c1[10] = {0}, c2[10] = {0};
//            for (int i = 0; i < n; i++){
//                c1[a[i]]++;
//                c2[b[i]]++;
//            }
//            for (int i = 1; i < 10; i++){
//                B += c1[i] > c2[i] ? c2[i] : c1[i];
//            }
//            printf("    (%d,%d)\n", A, B-A);
//        }
//    }
//    return 0;
//}


//2017-01-09-chenkuan

#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define maxn 100
int n;
int ans[maxn];
int seq[maxn];
int c1[10], c2[10];
int A, B;

int main() {
    //freopen("eg3-4(340).in", "r", stdin);
    int kase = 0;
    while (scanf("%d", &n) != EOF && n) {
        printf("Game %d:\n", ++kase);
        memset(c1, 0, sizeof(c1));
        for (int i = 0; i < n; i++) {
            scanf("%d", &ans[i]);
            c1[ans[i]]++;
        }
        while(1) {
            int isZero = 1;
            for (int i = 0; i < n; i++) {
                scanf("%d", &seq[i]);
                if (seq[i] != 0) isZero = 0;
            }
            if (isZero) break;

            memset(c2, 0, sizeof(c2));
            A = 0;
            for (int i = 0; i < n; i++) {
                c2[seq[i]] ++;
                if (seq[i] == ans[i]) {
                    A++;
                }
            }

            B = 0;
            for (int i = 0; i < 10; i++) {
                B += std::min(c1[i], c2[i]);
            }
            B -= A;
            printf("    (%d,%d)\n", A, B);
        }
    }
    return 0;
}