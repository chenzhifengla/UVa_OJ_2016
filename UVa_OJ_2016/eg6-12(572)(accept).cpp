//#include <cstdio>
//#include <cstring>
//const int maxn = 100 + 5;
//char pic[maxn][maxn];
//int m, n, idx[maxn][maxn];
//
//void dfs(int r, int c, int id) {
//	if (r < 0 || r >= m || c < 0 || c >= n) return;
//	if (idx[r][c] > 0 || pic[r][c] != '@') return;
//	idx[r][c] = id;
//	for (int dr = -1; dr <= 1; dr++) {
//		for (int dc = -1; dc <= 1; dc++) {
//			if (dr != 0 || dc != 0) dfs(r + dr, c + dc, id);
//		}
//	}
//}
//
//int main() {
//	while (scanf("%d%d", &m, &n) == 2 && m && n) {
//		for (int i = 0; i < m; i++) scanf("%s", pic[i]);
//		memset(idx, 0, sizeof(idx));
//		int cnt = 0;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (idx[i][j] == 0 && pic[i][j] == '@') dfs(i, j, ++cnt);
//			}
//		}
//		printf("%d\n", cnt);
//	}
//	return 0;
//}


// 2017-01-24-chenkuan

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(const vector<string>& grid, vector<vector<bool>>& idx, int r, int c) {
    idx[r][c] = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                if ((r + i) >= 0 && (r + i) < grid.size() 
                    && (c + j) >= 0 && (c + j) < grid[0].size() &&
                    grid[r + i][c + j] == '@' && !idx[r + i][c + j])
                dfs(grid, idx, r + i, c + j);
            }
        }
    }
}

int main() {
    //freopen("eg6-12(572).in", "r", stdin);
    int m, n;
    while (cin >> m >> n && m > 0) {
        vector<string> grid(m);
        for (auto& s : grid) {
            cin >> s;
        }
        int cnt = 0;
        vector<vector<bool>> idx(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!idx[i][j] && grid[i][j] == '@') {
                    dfs(grid, idx, i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}