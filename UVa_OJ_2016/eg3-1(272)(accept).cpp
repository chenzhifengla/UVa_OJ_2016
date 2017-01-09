//
// Created by chenkuaan on 7/27/16.
//

//#include <cstdio>
//
//int main(){
//    char c;
//    bool q = true;
//    while ((c = getchar()) != EOF){
//        if (c == '"'){
//            printf("%s", q ? "``" : "''");
//            q = !q;
//        }
//        else{
//            printf("%c", c);
//        }
//    }
//    return 0;
//}


//2017-01-09-chenkuan

#include <stdio.h>
char c;

int main() {
    int quote = 0;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            printf("%s", quote ? "''" : "``");
            quote = !quote;
        }
        else {
            putchar(c);
        }
    }
    return 0;
}