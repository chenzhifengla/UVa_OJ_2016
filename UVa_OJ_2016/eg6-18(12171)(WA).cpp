#include <cstdio>
#include <string.h>

const int maxn = 500 + 10;

int buf[maxn][maxn][maxn];
int flag[maxn][maxn][maxn];
int n;
int x0, y0, z0, x, y, z;
int minx, miny, minz, maxx, maxy, maxz;
int off[6][3] = {
	1, 0, 0,
	-1, 0, 0,
	0, 1, 0,
	0, -1, 0,
	0, 0, 1,
	0, 0, -1,
};

bool isInner(int x, int y, int z) {
	if (x < minx || x > maxx || y < miny || y > maxy || z < minz || z > maxz)
		return false;
	flag[x][y][z] = 1;
	for (int i = 0; i < 6; i++) {
		int x1 = x + off[i][0];
		int y1 = y + off[i][1];
		int z1 = z + off[i][2];
		if (buf[x1][y1][z1] == 0 && flag[x1][y1][z1] == 0 && !isInner(x1, y1, z1)) return false;
	}
	return true;
}

void fill(int x, int y, int z) {
	flag[x][y][z] = 0;
	for (int i = 0; i < 6; i++) {
		int x1 = x + off[i][0];
		int y1 = y + off[i][1];
		int z1 = z + off[i][2];
		if (buf[x1][y1][z1] == 0 && flag[x1][y1][z1] == 1) {
			fill(x1, y1, z1);
		}
	}
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(buf, 0, sizeof(buf));
		memset(flag, 0, sizeof(flag));
		minx = miny = minz = maxn - 1;
		maxx = maxy = maxz = 1;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d%d%d%d", &x0, &y0, &z0, &x, &y, &z);
			minx = x0 < minx ? x0 : minx;
			miny = y0 < miny ? y0 : miny;
			minz = z0 < minz ? z0 : minz;
			maxx = (x0 + x) > maxx ? (x0 + x) : maxx;
			maxy = (y0 + y) > maxy ? (y0 + y) : maxy;
			maxz = (z0 + z) > maxz ? (z0 + z) : maxz;
			for (int j = 0; j < x; j++) {
				for (int k = 0; k < y; k++) {
					for (int m = 0; m < z; m++) {
						buf[x0 + j][y0 + k][z0 + m] = 1;
					}
				}
			}
		}
		for (int i = minx; i <= maxx; i++) {
			for (int j = miny; j <= maxy; j++) {
				for (int k = minz; k <= maxz; k++) {
					if (buf[i][j][k] == 0 && flag[i][j][k] == 0) {
						if (isInner(i, j, k)) {
							fill(i, j, k);
						}
					}
				}
			}
		}
		int v = 0, surface = 0;
		for (int i = minx; i <= maxx; i++) {
			for (int j = miny; j <= maxy; j++) {
				for (int k = minz; k <= maxz; k++) {
					if (buf[i][j][k] == 1) {
						v++;
						for (int m = 0; m < 6; m++) {
							if (buf[i + off[m][0]][j + off[m][1]][k + off[m][2]] == 0) {
								surface++;
							}
						}
					}
				}
			}
		}
		printf("%d %d\n", v, surface);
	}
	return 0;
}