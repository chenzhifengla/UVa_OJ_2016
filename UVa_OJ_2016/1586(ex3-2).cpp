//
// Created by chenkuaan on 7/27/16.
//

#include <cstdio>
#include <cctype>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char s[100];
        scanf("%s", s);
        double sum = 0, price = 0;
        for (int i = 0; s[i]; i++){
            if (isalpha(s[i])) {
                if (s[i] == 'C') {
                    price = 12.01;
                }
                else if (s[i] == 'H') {
                    price = 1.008;
                }
                else if (s[i] == 'O') {
                    price = 16.00;
                }
                else if (s[i] == 'N') {
                    price = 14.01;
                }
                if (!isdigit(s[i + 1])) {
                    sum += price;
                }
            }
            else {
                int num = s[i] - '0';
                if (isdigit(s[i+1])) {
                    num = num * 10 + s[i + 1] - '0';
                    i++;
                }
                sum += price * num;
            }
        }
        printf("%g\n", sum);
    }
    return 0;
}