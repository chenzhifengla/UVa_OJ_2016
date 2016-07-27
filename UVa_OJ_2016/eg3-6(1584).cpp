//
// Created by chenkuaan on 7/27/16.
//

#include <cstdio>
#include <cstring>
#define maxn 105

bool less(const char* s, int n, int p, int q){
    for (int i = 0; i < n; i++){
        if (s[(p + i) % n] != s[(q + i) % n]){
            return s[(p + i) % n] < s[(q + i) % n];
        }
    }
    return 0;
}

int main(){
    int t;
    char s[maxn];
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        int n = strlen(s);
        int ans = 0;
        for (int i = 1; i < n; i++){
            if (less(s, n, i, ans)){
                ans = i;
            }
        }
        for (int i = 0; i < n; i++){
            putchar(s[(i + ans) % n]);
        }
        putchar('\n');
    }
    return 0;
}