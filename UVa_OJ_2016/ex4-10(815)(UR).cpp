#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int grid[900];

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	int m, n, kase = 0;
	while (scanf("%d%d", &m, &n) != EOF && m != 0) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &grid[i * n + j]);
			}
		}
		double sea;
		scanf("%lf", &sea);
		sea /= 100;
		qsort(grid, m * n, sizeof(int), cmp);
		int hasWater = 1;
		double seaLevel = 0;
		while (sea > 0 && hasWater < m * n) {
			double needWater = (grid[hasWater] - grid[hasWater - 1]) * hasWater;
			if (needWater >= sea) {
				seaLevel = grid[hasWater - 1] + sea / hasWater;
				break;
			}
			else {
				sea -= needWater;
				for (int i = 0; i < hasWater; i++) {
					grid[i] = grid[hasWater];
				}
				hasWater++;
			}
		}
		if (hasWater >= m * n) {
			seaLevel = grid[hasWater] + sea / hasWater;
		}
		if (hasWater == 1 && sea == 0) {
			seaLevel = 0;
			hasWater = 0;
		}
		if (kase > 0) printf("\n");
		printf("Region %d\n", ++kase);
		printf("Water level is %.2lf meters.\n", seaLevel);
		printf("%.2lf percent of the region is under water.\n", (double)hasWater / (m * n) * 100);
	}
	return 0;
}