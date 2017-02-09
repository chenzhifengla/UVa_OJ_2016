//#include <cstdio>
//#include <set>
//#include <algorithm>
//using namespace std;
//
//const int maxn = 1000000 + 5;
//int A[maxn];
//
//int main() {
//	int T, n;
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++) scanf("%d", &A[i]);
//
//		set<int> s;
//		int L = 0, R = 0, ans = 0;
//		while (R < n) {
//			while (R < n && !s.count(A[R])) s.insert(A[R++]);
//			ans = max(ans, R - L);
//			s.erase(A[L++]);
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}


// 2017-02-09-chenkuan

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> num;
            v.push_back(num);
        }
        auto L = v.begin(), R = v.begin();
        set<int> s;
        int ans = 0;
        while (R != v.end()) {
            while (R != v.end() && s.find(*R) == s.end()) {
                s.insert(*R);
                R++;
            }
            ans = max(ans, (int)(R - L));
            s.erase(*L);
            L++;
        }
        cout << ans << endl;
    }
    return 0;
}