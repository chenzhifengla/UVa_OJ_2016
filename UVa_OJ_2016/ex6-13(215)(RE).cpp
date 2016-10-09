#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <string.h>
using namespace std;

const int maxr = 20 + 2;
const int maxc = 10 + 2;

struct Ref {
	int plus;
	int x, y;
};

struct Cell {
	bool hasVal;
	int value;
	vector<Ref> refs;
}cells[maxr][maxc];
int flag[maxr][maxc];
int circle[maxr][maxc];

int r, c;

bool dfs(int x, int y) {
	flag[x][y] = 1;
	int sum = 0;
	for (int i = 0; i < cells[x][y].refs.size(); i++) {
		Ref ref = cells[x][y].refs[i];
		if (cells[ref.x][ref.y].hasVal) {
			if (ref.plus > 0) sum += cells[ref.x][ref.y].value;
			else sum -= cells[ref.x][ref.y].value;
		}
		else if (flag[ref.x][ref.y] == 1) {
			circle[x][y] = 1;
			return false;
		}
		else if (!dfs(ref.x, ref.y)) {
			circle[x][y] = 1;
			return false;
		}
		/*else if (!cells[ref.x][ref.y].hasVal) {
			printf("bug bug bug\n");
		}*/
		else {
			if (ref.plus > 0) sum += cells[ref.x][ref.y].value;
			else sum -= cells[ref.x][ref.y].value;
		}
	}
	cells[x][y].hasVal = true;
	cells[x][y].value = sum;
	return true;
}

int main() {
	int cnt = 0;
	while (scanf("%d%d", &r, &c) != EOF && r != 0 && c != 0) {
		memset(cells, 0, sizeof(cells));
		memset(flag, 0, sizeof(flag));
		memset(circle, 0, sizeof(circle));
		string s;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> s;
				if (isdigit(s[0]) != 0) {
					stringstream ss(s);
					int num;
					ss >> num;
					Cell cell;
					cell.hasVal = true;
					cell.value = num;
					cells[i][j] = cell;
				}
				else {
					Cell cell;
					cell.hasVal = false;

					Ref ref;
					ref.plus = 1;
					ref.x = s[0] - 'A';
					ref.y = s[1] - '0';
					cell.refs.push_back(ref);
					for (int k = 2; k < s.length();) {
						if (s[k] == '+') ref.plus = 1;
						else ref.plus = -1;
						ref.x = s[k + 1] - 'A';
						ref.y = s[k + 2] - '0';
						cell.refs.push_back(ref);
						k += 3;
					}
					cells[i][j] = cell;
				}
			}
		}
		bool hasCircle = false;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (!cells[i][j].hasVal && circle[i][j] != 1) {
					if (!dfs(i, j)) hasCircle = true;
				}
			}
		}
		if (cnt++ != 0) printf("\n");
		if (!hasCircle) {
			printf(" ");
			for (int i = 0; i < c; i++) {
				printf("%5d", i);
			}
			printf("\n");
			for (int i = 0; i < r; i++) {
				printf("%c", i + 'A');
				for (int j = 0; j < c; j++) {
					printf("%5d", cells[i][j].value);
				}
				printf("\n");
			}
		}
		else {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (circle[i][j] == 1) {
						printf("%c%d: %c%d", i + 'A', j, cells[i][j].refs[0].x + 'A',
							cells[i][j].refs[0].y);
						for (int k = 1; k < cells[i][j].refs.size(); k++) {
							if (cells[i][j].refs[k].plus > 0) printf("+");
							else printf("-");
							printf("%c%d", cells[i][j].refs[k].x + 'A',
								cells[i][j].refs[k].y);
						}
						printf("\n");
					}
				}
			}
		}
	}
	return 0;
}