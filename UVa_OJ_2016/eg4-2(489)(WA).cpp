//#include <cstdio>
//#include <cstring>
//#define maxn 100
//
//int left, chance;	//还要猜left个位置，错chance次之后就会输
//char s1[maxn], s2[maxn];	//答案是字符串s1, 玩家猜的是字符串s2
//int win, lose;	//win=1表示赢了，lose=1表示输了
//
//void guess(char ch) {
//	int bad = 1;
//	for (int i = 0; i < strlen(s1); i++) {
//		if (s1[i] == ch) {
//			left--;
//			s1[i] = ' ';
//			bad = 0;
//		}
//	}
//	if (bad) chance--;
//	if (!chance) lose = 1;
//	if (!left) win = 1;
//}
//
//int main() {
//	int rnd;
//	while (scanf("%d", &rnd) == 1 && rnd != -1) {
//		scanf("%s%s", s1, s2);
//		printf("Round %d\n", rnd);
//		win = lose = 0;
//		left = strlen(s1);
//		chance = 7;
//		for (int i = 0; i < strlen(s2); i++) {
//			guess(s2[i]);
//			if (win || lose) break;
//		}
//		//根据结果进行输出
//		if (win) printf("You win.\n");
//		else if (lose) printf("You lose.\n");
//		else printf("You chickened out.\n");
//	}
//	return 0;
//}


//2017-01-10-chenkuan

#include <stdio.h>
#include <string.h>
#define maxn 100
int n;
char ans[maxn], guess[maxn];

int main() {
    //freopen("eg4-2(489).in", "r", stdin);
    while (scanf("%d%s%s", &n, ans, guess) != EOF && n != -1) {
        int len_guess = strlen(guess);
        int len_ans = strlen(ans);
        int times = 0;
        for (int i = 0; i < len_guess; i++) {
            char c = guess[i];
            int find = 0;
            for (int j = 0; j < len_ans; j++) {
                if (ans[j] == c) {
                    find = 1;
                    ans[j] = ' ';
                }
            }
            if (find == 0) {
                times++;
            }
        }
        printf("Round %d\n", n);
        if (times > 6) {
            printf("You lose.\n");
        }
        else {
            int win = 1;
            for (int i = 0; i < len_ans; i++) {
                if (ans[i] != ' ') {
                    win = 0;
                }
            }
            if (win) {
                printf("You win.\n");
            }
            else {
                printf("You chickened out.\n");
            }
        }
    }
    return 0;
}