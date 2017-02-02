//#include <stdio.h>
//
//int cnt, n, L;
//int S[100];
//
//int dfs(int cur) {
//	if (cnt++ == n) {
//		for (int i = 0; i < cur; i++) {
//			printf("%c", 'A' + S[i]);
//			
//			if ((i + 1) % 4 == 0) printf(" ");
//			if ((i + 1) % 64 == 0) printf("\n");
//		}
//		printf("\n%d\n", cur);
//		return 0;
//	}
//	for (int i = 0; i < L; i++) {
//		S[cur] = i;
//		int ok = 1;
//		for (int j = 1; j * 2 <= cur + 1; j++) {
//			int equal = 1;
//			for (int k = 0; k < j; k++) {
//				if (S[cur - k] != S[cur - k - j]) {
//					equal = 0;
//					break;
//				}
//			}
//			if (equal) {
//				ok = 0;
//				break;
//			}
//		}
//		if (ok) {
//			if (!dfs(cur + 1)) return 0;
//		}
//	}
//	return 1;
//}
//
//int main() {
//	while (scanf("%d%d", &n, &L) != EOF && n != 0 && L != 0) {
//		cnt = 0;
//		dfs(0);
//	}
//	return 0;
//}


// 2017-02-02-chenkuan

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n, L;
string ans;
int cnt;

bool dfs() {
    if (cnt++ == n) {
        for (int i = 0; i < ans.size(); i++) {
            if (i > 0 && i % 64 == 0) cout << endl;
            else if (i > 0 && i % 4 == 0) cout << ' ';
            cout << ans[i];
        }
        cout << endl << ans.size() << endl;
        return true;
    }
    for (char c = 'A'; c < 'A' + L; c++) {
        ans.push_back(c);
        bool ok = true;
        for (int i = 1; i <= ans.size() / 2; i++) {
            if (ans.compare(ans.size() - i * 2, i, ans, ans.size() - i, i) == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            if (dfs()) return true;
        }
        ans.pop_back();
    }
    return false;
}

int main() {
    while (cin >> n >> L) {
        if (n == 0 && L == 0) break;
        ans.clear();
        cnt = 0;
        dfs();
    }
    return 0;
}