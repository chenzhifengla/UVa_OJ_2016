//
// Created by chenkuaan on 7/27/16.
//

//#include <cstdio>
//#include <cstring>
//#define maxn 105
//
//bool less(const char* s, int n, int p, int q){
//    for (int i = 0; i < n; i++){
//        if (s[(p + i) % n] != s[(q + i) % n]){
//            return s[(p + i) % n] < s[(q + i) % n];
//        }
//    }
//    return 0;
//}
//
//int main(){
//    int t;
//    char s[maxn];
//    scanf("%d", &t);
//    while(t--){
//        scanf("%s", s);
//        int n = strlen(s);
//        int ans = 0;
//        for (int i = 1; i < n; i++){
//            if (less(s, n, i, ans)){
//                ans = i;
//            }
//        }
//        for (int i = 0; i < n; i++){
//            putchar(s[(i + ans) % n]);
//        }
//        putchar('\n');
//    }
//    return 0;
//}

//2017-01-10-chenkuan

#include <stdio.h>
#include <string.h>
int t, len, min_pos;
char ring[110];

int less(int pos) {
    for (int i = 0; i < len; i++) {
        if (ring[(pos + i) % len] != ring[(min_pos + i) % len])
            return ring[(pos + i) % len] < ring[(min_pos + i) % len];
    }
    return 0;
}

int main() {
    //freopen("eg3-6(1584).in", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        scanf("%s", ring);
        len = strlen(ring);
        min_pos = 0;
        for (int i = 1; i < len; i++) {
            if (less(i)) {
                min_pos = i;
            }
        }
        printf("%s", ring + min_pos);
        ring[min_pos] = '\0';
        printf("%s\n", ring);
    }
    return 0;
}