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
        double sum = 0, price = 0, num = 0;
        for (int i = 0; s[i]; i++){
            if (isalpha(s[i])) {
                sum += price * (num == 0 ? 1 : num);
                num = 0;
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
            }
            else {
                num = num * 10 + s[i] - '0';
            }
        }
        sum += price * (num == 0 ? 1 : num);
        printf("%.3f\n", sum);
    }
    return 0;
}