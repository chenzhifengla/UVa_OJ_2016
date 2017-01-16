//#include <cstdio>
//#include <algorithm>
//using namespace std;
//const int maxn = 10000;
//
//int main() {
//	int n, q, x, a[maxn], kase = 0;
//	while (scanf("%d%d", &n, &q) == 2 && n) {
//		printf("CASE# %d:\n", ++kase);
//		for (int i = 0; i < n; i++) {
//			scanf("%d", &a[i]);
//		}
//		sort(a, a + n);
//		while (q--) {
//			scanf("%d", &x);
//			int p = lower_bound(a, a + n, x) - a;
//			if (a[p] == x) {
//				printf("%d found at %d\n", x, p + 1);
//			}
//			else printf("%d not found\n", x);
//		}
//	}
//	return 0;
//}


// 2017-01-16-chenkuan

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, q;
vector<int> v;

int main() {
    //freopen("eg5-1(10474).in", "r", stdin);
    int kase = 0;
    while (cin >> n >> q) {
        if (n == 0 || q == 0) break;
        cout << "CASE# " << ++kase << ":" << endl;
        v.clear();
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < q; i++) {
            cin >> x;
            auto it = find(v.begin(), v.end(), x);
            if (it != v.end()) {
                cout << x << " found at " << it - v.begin() + 1 << endl;
            }
            else {
                cout << x << " not found" << endl;
            }
        }
    }
    return 0;
}