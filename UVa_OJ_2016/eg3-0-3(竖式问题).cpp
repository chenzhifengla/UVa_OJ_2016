//2017-01-09-chenkuan

#include <stdio.h>
#include <memory.h>
char set[10];
int buf[10];

int isLegal(int num) {
    while (num) {
        if (buf[num % 10] == 0) return 0;
        num /= 10;
    }
    return 1;
}

int main() {
    while (scanf("%s", set) != EOF) {
        memset(buf, 0, sizeof(buf));
        for (int i = 0; set[i] != '\0'; i++) {
            buf[set[i] - '0'] = 1;
        }
        int solutions = 0;
        for (int i = 100; i < 1000; i++) {
            if (!isLegal(i)) continue;
            for (int j = 10; j < 100; j++) {
                if (isLegal(j) &&
                    isLegal(i * (j % 10)) &&
                    isLegal(i * (j / 10)) &&
                    isLegal(i * j)) {
                    printf("%5d\n", i);
                    printf("X%4d\n", j);
                    printf("-----\n");
                    printf("%5d\n", i * (j % 10));
                    printf("%-5d\n", i * (j / 10));
                    printf("-----\n");
                    printf("%5d\n\n", i * j);
                    solutions++;
                }
            }
        }
        printf("The number of solutions = %d\n", solutions);
    }
    return 0;
}