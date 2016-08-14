#include <stdio.h>
#include <string.h>
int d, s, b;
char check[2];
char disk[7][7000];
char binaryAnswer[50000];

int main() {
	int kase = 0;
	while (scanf("%d", &d) != EOF && d != 0) {
		scanf("%d%d%s", &s, &b, check);
		int checkStyle = check[0] == 'E' ? 0 : 1;
		memset(disk, 0, sizeof(disk));
		for (int i = 0; i < d; i++) {
			scanf("%s", disk[i]);
		}
		int isValid = 1;
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < s; j++) {
				int xNum = 0;
				int xIndex = -1;
				for (int k = 0; k < d; k++) {
					if (disk[k][i * s + j] == 'x') {
						xNum++;
						xIndex = k;
					}
				}
				if (xNum > 1) {
					isValid = 0;
					break;
				}
				else if (xNum == 1) {
					int first;
					if (xIndex == 0) {
						first = disk[1][i * s + j] - '0';
						for (int k = 2; k < d; k++) {
							first ^= (disk[k][i * s + j] - '0');
						}
					}
					else {
						first = disk[0][i * s + j] - '0';
						for (int k = 1; k < d; k++) {
							if (disk[k][i * s + j] == 'x') continue;
							first ^= (disk[k][i * s + j] - '0');
						}
					}
					disk[xIndex][i * s + j] = (first ^ checkStyle) + '0';
				}
				else {
					int first = disk[0][i * s + j] - '0';
					for (int k = 1; k < d; k++) {
						first ^= (disk[k][i * s + j] - '0');
					}
					if (first != checkStyle) {
						isValid = 0;
						break;
					}
				}
			}
			if (!isValid) break;
		}
		if (!isValid) {
			printf("Disk set %d is invalid\n", ++kase);
		}
		else {
			printf("Disk set %d is valid, contents are: ", ++kase);
			int binaryAnswerLen = 0;
			for (int i = 0; i < b; i++) {
				for (int j = 0; j < d; j++) {
					if (i % d == j) continue;
					for (int k = 0; k < s; k++) {
						binaryAnswer[binaryAnswerLen++] = disk[j][i * s + k] - '0';
					}
				}
			}
			int num = binaryAnswerLen / 4;
			for (int i = 0; i < num; i++) {
				int n = 0;
				for (int j = 0; j < 4; j++) {
					n *= 2;
					n += binaryAnswer[i * 4 + j];
				}
				printf("%X", n);
			}
			int remainNum = binaryAnswerLen % 4;
			int n = 0;
			for (int i = 0; i < remainNum; i++) {
				n *= 2;
				n += binaryAnswer[num * 4 + i];
			}
			for (int i = remainNum; i < 4; i++) {
				n *= 2;
			}
			if (remainNum) printf("%X", n);
			printf("\n");
		}
	}
	return 0;
}