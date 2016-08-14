#include <stdio.h>
#include <string.h>
char cube1[10], cube2[10], cubeR[10];
int nei[6][4] = {
	2, 4, 5, 3,		//从上往下看逆时针遍历
	1, 3, 6, 4,
	2, 1, 5, 6,
	1, 2, 6, 5,
	1, 4, 6, 3,
	4, 2, 3, 5,
};

int main() {
	char buf[15];
	while (scanf("%s", buf) != EOF) {
		for (int i = 0; i < 6; i++) {
			cube1[i] = buf[i];
		}
		cube1[6] = '\0';
		for (int i = 6; i < 12; i++) {
			cube2[i - 6] = buf[i];
		}
		cube2[6] = '\0';
		int equal = 0;
		for (int i = 0; i < 6; i++) {	//遍历6个面各自朝上时
			for (int j = 0; j < 4; j++) {	//旋转成4个方向
				cubeR[0] = cube1[i];
				cubeR[1] = cube1[nei[i][(0 + j) % 4] - 1];
				cubeR[2] = cube1[nei[i][(3 + j) % 4] - 1];
				cubeR[3] = cube1[nei[i][(1 + j) % 4] - 1];
				cubeR[4] = cube1[nei[i][(2 + j) % 4] - 1];
				cubeR[5] = cube1[5 - i];
				cubeR[6] = '\0';
				if (strcmp(cubeR, cube2) == 0) {
					equal = 1;
					break;
				}
			}
			if (equal) break;
		}
		if (equal) printf("TRUE\n");
		else printf("FALSE\n");
	}
	return 0;
}