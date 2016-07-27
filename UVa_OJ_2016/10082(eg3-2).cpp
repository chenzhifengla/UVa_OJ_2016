//
// Created by chenkuaan on 7/27/16.
//

#include <cstdio>

int main(){
    char s[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
    int c;
    while ((c = getchar()) != EOF){
        int index;
        for (index = 0; s[index] && s[index] != c; index++);
        if (s[index]){
            printf("%c", s[index-1]);
        }
        else{
            printf("%c", c);
        }
    }
    return 0;
}