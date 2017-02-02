//#include <cstdio>
//
//int k;
//
//int main() {
//	while (scanf("%d", &k) != EOF) {
//		for (int y = k + 1; y <= 2 * k; y++) {
//			if ((k * y) % (y - k) == 0) {
//				int x = (k * y) / (y - k);
//				if (x < y) continue;
//				printf("1/%d = 1/%d + 1/%d\n", k, x, y);
//			}
//		}
//	}
//	return 0;
//}


// 2017-01-30-chenkuan

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    while (cin >> k) {
        int ans = 0;
        vector<int> X, Y;
        for (int i = k + 1; i <= k * 2; i++) {
            int x = k * i / (i - k);
            if (x * (i - k) == k * i) {
                ans++;
                X.push_back(x);
                Y.push_back(i);
            }
        }
        cout << ans << endl;
        for (int i = 0; i < X.size(); i++) {
            cout << "1/" << k << " = 1/" << X[i] << " + 1/" << Y[i] << endl;
        }
    }
    return 0;
}