//
// Created by chenkuaan on 7/27/16.
//

#include <cstdio>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char s[100];
        scanf("%s", s);
        int score = 0, con = 0;
        for (int i = 0; s[i]; i++){
            if (s[i] == 'O'){
                con++;
                score += con;
            }
            else {
                con = 0;
            }
        }
        printf("%d\n", score);
    }
    return 0;
}