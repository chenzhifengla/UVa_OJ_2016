//#include <cstdio>
//#include <cctype>
//#include <cstring>
//using namespace std;
//
//const int maxn = 200 + 10;
//int n;
//char buf[maxn][maxn];
//
//void dfs(int r, int c) {
//	printf("%d(", buf[r][c]);
//	if (r + 1 < n && buf[r + 1][c] == '|') {
//		int i = c;
//		while (i - 1 >= 0 && buf[r + 2][i - 1] == '-') i--;
//		while (buf[r + 1][i] == '-' && buf[r + 3][i] != '\0') {
//			if (!isspace(buf[r + 3][i])) {
//				dfs(r + 3, i);
//			}
//			i++;
//		}
//	}
//	printf(")");
//}
//
//void solve() {
//	n = 0;
//	for (;;) {
//		fgets(buf[n], maxn, stdin);
//		if (buf[n][0] == '#') {
//			break;
//		}
//		else {
//			n++;
//		}
//		printf("(");
//		if (n) {
//			for (int i = 0; i < strlen(buf[0]); i++) {
//				if (buf[0][i] != ' ') {
//					dfs(0, i);
//					break;
//				}
//			}
//		}
//		printf(")\n");
//	}
//}
//
//int main() {
//	int t;
//	fgets(buf[0], maxn, stdin);
//	sscanf(buf[0], "%d", &t);
//	while (t--) {
//		solve();
//	}
//	return 0;
//}


// 2017-01-26-chenkuan

#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> G;

void dfs(int r, int c) {
    cout << G[r][c] << '(';
    if (r + 1 < G.size() && G[r + 1][c] == '|') {
        int leftc = c;
        while (leftc - 1 >= 0 && G[r + 2][leftc - 1] == '-') leftc--;
        while (G[r + 2][leftc] == '-' && leftc < G[r + 3].size()) {
            if (G[r + 3][leftc] != ' ') {
                dfs(r + 3, leftc);
            }
            leftc++;
        }
    }
    cout << ')';
}

int main() {
    //freopen("eg6-17(10562).in", "r", stdin);
    int t;
    cin >> t;
    string line;
    getline(cin, line);
    while (t--) {
        G.clear();
        while (getline(cin, line) && line != "#") {
            G.push_back(line);
        }
        cout << '(';
        if (G.size() != 0) {
            for (int i = 0; i < G[0].size(); i++) {
                if (G[0][i] != ' ') {
                    dfs(0, i);
                    break;
                }
            }
        }
        cout << ')' << endl;
    }
    return 0;
}