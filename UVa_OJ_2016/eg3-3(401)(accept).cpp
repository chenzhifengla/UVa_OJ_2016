//
// Created by chenkuaan on 7/27/16.
//

//#include <cstdio>
//#include <cstring>
//#include <cctype>
//
//const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
//char reverse(char c){
//    if (isalpha(c)) return rev[c - 'A'];
//    else return rev[c - '0' + 25];
//}
//
//int main(){
//
//    const char* msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
//
//    char s[100];
//    while(scanf("%s", s) != EOF){
//        int len = strlen(s);
//        int isPalidrom = 1, ismirrored = 1;
//        for (int i = 0; i < (len + 1) / 2; i++){
//            if (s[i] != s[len - 1 - i]) isPalidrom = 0;
//            if (reverse(s[i]) != s[len - 1 - i]) ismirrored = 0;
//        }
//        printf("%s -- is %s.\n\n", s, msg[ismirrored * 2 + isPalidrom]);
//    }
//    return 0;
//}


//2017-01-09-chenkuan

#include <stdio.h>
#include <string.h>
#include <ctype.h>
const char* mirror = "A***3**HIL*JM*O***2TUVWXY51SE*Z**8*";
const char* msg[] = { "not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome" };
char buf[1000];
int len;

char r(char ch) {
    if (isalpha(ch)) return mirror[ch - 'A'];
    else return mirror[ch - '0' + 25];
}

int main() {
    while (scanf("%s", buf) != EOF) {
        len = strlen(buf);
        int isP = 1, isM = 1;
        for (int i = 0; i < (len + 1) / 2; i++) {
            if (buf[i] != buf[len - 1 - i]) isP = 0;
            if (r(buf[i]) != buf[len - 1 - i]) isM = 0;
        }
        printf("%s -- is %s.\n\n", buf, msg[isM * 2 + isP]);
    }
    return 0;
}