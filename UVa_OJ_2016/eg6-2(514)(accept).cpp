//#include <cstdio>
//#include <stack>
//using namespace std;
//const int MAXN = 1000 + 10;
//int n, target[MAXN];
//
//int main() {
//	while (scanf("%d", &n) == 1) {
//		stack<int> s;
//		int A = 1, B = 1;
//		for (int i = 1; i <= n; i++) {
//			scanf("%d", &target[i]);
//		}
//		int ok = 1;
//		while (B <= n) {
//			if (A == target[B]) {
//				A++;
//				B++;
//			}
//			else if (!s.empty() && s.top() == target[B]) {
//				s.pop();
//				B++;
//			}
//			else if (A <= n) {
//				s.push(A++);
//			}
//			else {
//				ok = 0;
//				break;
//			}
//		}
//		printf("%s\n", ok ? "Yes" : "No");
//	}
//	return 0;
//}


// 2017-01-20-chenkuan

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int x;
        while (cin >> x && x != 0) {
            int a, b;
            stack<int> S;
            queue<int> B;
            B.push(x);
            for (int i = 1; i < n; i++) {
                cin >> x;
                B.push(x);
            }
            bool ok = true;
            int num = 1;
            while (!B.empty()) {
                if (num == B.front()) {
                    num++;
                    B.pop();
                }
                else if (!S.empty() && S.top() == B.front()) {
                    S.pop();
                    B.pop();
                }
                else if (num <= n) {
                    S.push(num++);
                }
                else {
                    ok = false;
                    break;
                }
            }
            if (ok) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}