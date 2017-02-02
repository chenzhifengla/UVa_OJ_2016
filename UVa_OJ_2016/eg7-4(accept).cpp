//#include <stdio.h>
//
//int n;
//int A[21];
//int vis[21] = { 0 };
//int isp[21] = { 0 };
//
//void dfs(int cur) {
//	if (cur == n && isp[A[0] + A[n - 1]]) {
//		for (int i = 0; i < n - 1; i++) printf("%d ", A[i]);
//		printf("%d\n", A[n - 1]);
//	}
//	else for (int i = 2; i <= n; i++) {
//		if (!vis[i] && isp[i + A[cur - 1]]) {
//			A[cur] = i;
//			vis[i] = 1;
//			dfs(cur + 1);
//			vis[i] = 0;
//		}
//	}
//}
//
//int main() {
//	for (int i = 0; i < 21; i++) {
//		A[i] = i + 1;
//		isp[i] = 1;
//	}
//	for (int i = 2; i < 21; i++) {
//		for (int j = 2; j <= i; j++) {
//			if (i * j < 21 && isp[j] == 1) {
//				isp[i * j] = 0;
//			}
//		}
//	}
//	int cnt = 0;
//	while (scanf("%d", &n) != EOF) {
//		if (cnt) printf("\n");
//		printf("Case %d:\n", ++cnt);
//		A[0] = 1;
//		dfs(1);
//	}
//	return 0;
//}


// 2017-02-02-chenkuan

#include <iostream>
#include <vector>
using namespace std;
vector<bool> is_prime;
vector<int> ring;
vector<bool> vis;
int n;

void dfs() {
    if (ring.size() == n && is_prime[ring[0] + ring[n - 1]]) {
        for (auto it = ring.cbegin(); it != ring.cend() - 1; it++) {
            cout << *it << ' ';
        }
        cout << ring.back() << endl;
    }
    else for (int i = 2; i <= n; i++) {
        if (vis[i] == false && is_prime[i + ring.back()]) {
            ring.push_back(i);
            vis[i] = true;
            dfs();
            vis[i] = false;
            ring.pop_back();
        }
    }
}

int main() {
    int kase = 0;
    while (cin >> n) {
        if (kase) cout << endl;
        cout << "Case " << ++kase << ":" << endl;
        is_prime.assign(n * 2 + 1, true);
        is_prime[1] = false;
        for (int i = 2; i <= n; i++) {
            for (int j = 2; i * j <= n * 2; j++) {
                is_prime[i * j] = false;
            }
        }
        ring.assign(1, 1);
        vis.assign(n + 1, false);
        vis[0] = true;
        dfs();
    }
    return 0;
}