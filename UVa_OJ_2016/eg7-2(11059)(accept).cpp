//#include <cstdio>
//
//int buf[18];
//
//long long max;
//
//int main() {
//	int n, cnt = 1;
//	while (scanf("%d", &n) != EOF && n != 0) {
//		max = 0;
//		for (int i = 0; i < n; i++) {
//			scanf("%d", &buf[i]);
//		}
//		int begin, end;
//		long long ans = 1;
//		for (begin = 0; begin < n; begin++) {
//			for (end = begin; end < n; end++) {
//				ans = 1;
//				for (int i = begin; i <= end; i++) {
//					ans *= buf[i];
//				}
//				max = ans > max ? ans : max;
//			}
//		}
//		printf("Case #%d: The maximum product is %lld.\n\n", cnt, max);
//	}
//	return 0;
//}


// 2017-01-30-chenkuan

#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("eg7-2(11059).in", "r", stdin);
    freopen("eg7-2(11059).out", "w", stdout);
#endif // LOCAL

    int n, kase = 1;
    while (cin >> n) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        long long ans = nums[0], sum = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                sum = nums[i];
                for (int k = i + 1; k <= j; k++) {
                    sum *= nums[k];
                }
                if (sum > ans) ans = sum;
            }
        }
        cout << "Case #" << kase++ << ": The maximum product is ";
        if (ans <= 0) cout << "0";
        else cout << ans;
        cout << "." << endl << endl;
    }
    return 0;
}