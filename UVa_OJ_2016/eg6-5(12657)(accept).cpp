//#include <iostream>
//
//const int maxn = 100000 + 5;
//int left[maxn], right[maxn];
//int n;
//
//void link(int L, int R) {
//	right[L] = R;
//	left[R] = L;
//}
//
//int main() {
//	int m, kase = 0;
//	while (scanf("%d%d", &n, &m) == 2) {
//		for (int i = 1; i <= n; i++) {
//			left[i] = i - 1;
//			right[i] = (i + 1) % (n + 1);
//		}
//		right[0] = 1;
//		left[0] = n;
//		int op, X, Y, inv = 0;
//		while (m--) {
//			scanf("%d", &op);
//			if (op == 4) inv = !inv;
//			else {
//				scanf("%d%d", &X, &Y);
//				if (op == 3 && right[Y] == X) std::swap(X, Y);
//				if (op != 3 && inv) op = 3 - op;
//				if (op == 1 && X == left[Y]) continue;
//				if (op == 2 && X == right[Y]) continue;
//
//				int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
//				if (op == 1) {
//					link(LX, RX);
//					link(LY, X);
//					link(X, Y);
//				}
//				else if (op == 2) {
//					link(LX, RX);
//					link(Y, X);
//					link(X, RY);
//				}
//				else if (op == 3) {
//					if (right[X] == Y) {
//						link(LX, Y);
//						link(Y, X);
//						link(X, RY);
//					}
//					else {
//						link(LX, Y);
//						link(Y, RX);
//						link(LY, X);
//						link(X, RY);
//					}
//				}
//			}
//		}
//		int b = 0;
//		long long ans = 0;
//		for (int i = 1; i <= n; i++) {
//			b = right[b];
//			if (i % 2 == 1) ans += b;
//		}
//		if (inv && n % 2 == 0) ans = (long long)n * (n + 1) / 2 - ans;
//		printf("Case %d: %lld\n", ++kase, ans);
//	}
//	return 0;
//}


// 2017-01-22-chenkuan

#include <iostream>
#include <vector>
using namespace std;
vector<int> lefti, righti;

void link(int L, int R) {
    righti[L] = R;
    lefti[R] = L;
}

int main() {
    //freopen("eg6-5(12657).in", "r", stdin);
    int n, m, kase = 0;
    while (cin >> n >> m) {
        lefti.clear();
        righti.clear();
        lefti.push_back(n);
        righti.push_back(1);
        for (int i = 1; i <= n; i++) {
            lefti.push_back(i - 1);
            righti.push_back((i + 1) % (n + 1));
        }
        int op, x, y;
        bool inv = false;
        for (int i = 0; i < m; i++) {
            //for (int i = right[0]; i <= n; i = right[i]) {
            //    cout << i << ' ';
            //}
            //cout << endl;
            cin >> op;
            if (op == 4) {
                inv = !inv;
                continue;
            }
            cin >> x >> y;
            if (op != 3 & inv) op = 3 - op; // 此处是为了inv转换
            if (op == 1 && x == lefti[y]) continue;
            if (op == 2 && x == righti[y]) continue;
            if (op == 3 && righti[y] == x) swap(x, y);  // 此处是为了统一处理x,y和y,x的两种相邻项
            
            int LX = lefti[x], LY = lefti[y], RX = righti[x], RY = righti[y];
            if (op == 1) {
                link(LX, RX);
                link(LY, x);
                link(x, y);
            }
            else if (op == 2) {
                link(LX, RX);
                link(y, x);
                link(x, RY);
            }
            else if (op == 3) {
                if (RX == y) {
                    link(LX, y);
                    link(y, x);
                    link(x, RY);
                }
                else {
                    link(LX, y);
                    link(y, RX);
                    link(LY, x);
                    link(x, RY);
                }
            }
        }
        long long ans = 0;
        int b = 0;
        for (int i = 1; i <= n; i++) {
            b = righti[b];
            if (i % 2 == 1) ans += b;
        }
        if (inv && n % 2 == 0) ans = (long long)n * (n + 1) / 2 - ans;
        cout << "Case " << ++kase << ": " << ans << endl;
    }
    return 0;
}