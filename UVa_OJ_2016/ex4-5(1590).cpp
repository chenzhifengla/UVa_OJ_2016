#include <stdio.h>
#include <math.h>

int compare(int ip1, int ip2) {
	int equal = 0;
	for (int i = 0; i < 8; i++) {
		ip1 <<= 1;
		ip2 <<= 1;
		if (ip1 / 256 == ip2 / 256) {
			equal++;
			ip1 %= 256;
			ip2 %= 256;
		}
		else return equal;
	}
}

int main() {
	int m;
	while (scanf("%d", &m) != EOF) {
		int address[4];
		scanf("%d.%d.%d.%d", &address[0], &address[1], &address[2], &address[3]);
		m--;
		int minindex[2] = { 3, 8 };
		while (m--) {
			int ip[4];
			scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
			int index[2] = { 3, 8 };
			for (int i = 0; i < 4; i++) {
				if (address[i] != ip[i]) {
					index[0] = i;
					index[1] = compare(address[i], ip[i]);
					break;
				}
			}
			if (index[0] < minindex[0]) {
				minindex[0] = index[0];
				minindex[1] = index[1];
			}
			else if (index[0] == minindex[0] && index[1] < minindex[1]) {
				minindex[1] = index[1];
			}
		}
		int mask[4] = { 0 };
		for (int i = 0; i < minindex[0]; i++) {
			mask[i] = 255;
		}
		mask[minindex[0]] = 256 - (int)pow(2, 8 - minindex[1]);
		for (int i = 0; i < 4; i++) {
			address[i] &= mask[i];
		}
		for (int i = 0; i < 3; i++) {
			printf("%d.", address[i]);
		}
		printf("%d\n", address[3]);
		for (int i = 0; i < 3; i++) {
			printf("%d.", mask[i]);
		}
		printf("%d\n", mask[3]);
	}
	return 0;
}