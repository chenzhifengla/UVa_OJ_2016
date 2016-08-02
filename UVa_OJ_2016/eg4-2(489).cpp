#include <cstdio>
#include <cstring>
#define maxn 100

int left, chance;	//��Ҫ��left��λ�ã���chance��֮��ͻ���
char s1[maxn], s2[maxn];	//�����ַ���s1, ��Ҳµ����ַ���s2
int win, lose;	//win=1��ʾӮ�ˣ�lose=1��ʾ����

void guess(char ch) {
	int bad = 1;
	for (int i = 0; i < strlen(s1); i++) {
		if (s1[i] == ch) {
			left--;
			s1[i] = ' ';
			bad = 0;
		}
	}
	if (bad) chance--;
	if (!chance) lose = 1;
	if (!left) win = 1;
}

int main() {
	int rnd;
	while (scanf("%d", &rnd) == 1 && rnd != -1) {
		scanf("%s%s", s1, s2);
		printf("Round %d\n", rnd);
		win = lose = 0;
		left = strlen(s1);
		chance = 7;
		for (int i = 0; i < strlen(s2); i++) {
			guess(s2[i]);
			if (win || lose) break;
		}
		//���ݽ���������
		if (win) printf("You win.\n");
		else if (lose) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
	return 0;
}