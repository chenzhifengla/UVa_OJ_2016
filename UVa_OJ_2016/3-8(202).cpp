#include <cstdio>

int main() {
	int fz, fm;
	while (scanf("%d%d", &fz, &fm) != EOF) {
		printf("%d/%d = ");
		int zs = fz / fm;
		printf("%d.", zs);
		fz %= fm;
		//digit array
		int reminder[1001];
		int quotient[1001];
		int len_rem = 0;
		int len_quo = 0;
		int len_rec = 0;
		reminder[len_rem++] = fz;
		while (1) {
			fz *= 10;
			quotient[len_quo++] = fz / fm;
			fz %= fm;
			if (fz == 0) {
				break;
			}
			else {
				bool flag = false;
				for (int i = 0; i < len_rem; i++) {
					if (reminder[i] == fz) {
						len_rec = len_quo;
						flag = true;
						break;
					}
				}
				if (flag) {
					break;
				}
				else {
					reminder[len_rem++] = fz;
				}
			}
		}
		if (fz == 0) {
			for (int i = 0; i < len_quo; i++) {
				printf("%d", quotient[i]);
			}
			printf("(0)\n");
			//%d = number of digits in repeating cycle", 
		}
		else {
			printf("(");
			for (int i = 0; i < len_quo && i < 50; i++) {
				printf("%d", quotient[i]);
			}
			if (len_quo > 50) {
				printf("...");
			}
			printf(")\n");
		}
		printf("   %d = number of digits in repeating cycle", len_rec);
	}
	return 0;
}