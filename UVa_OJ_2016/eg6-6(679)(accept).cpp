//#include <cstdio>
//#include <cstring>
//const int maxd = 20;
//int s[1 << maxd];
//int main() {
//	int D, I;
//	while (scanf("%d%d", &D, &I) == 2) {
//		memset(s, 0, sizeof(s));
//		int k, n = (1 << D) - 1;
//		for (int i = 0; i < I; i++) {
//			k = 1;
//			for (;;) {
//				s[k] = !s[k];
//				k = s[k] ? k * 2 : k * 2 + 1;
//				if (k > n) break;
//			}
//		}
//		printf("%d\n", k / 2);
//	}
//	return 0;
//}


// 2017-01-22-chenkuan

#include <iostream>
using namespace std;

int main() {
    //freopen("eg6-6(679).in", "r", stdin);
    int n;
    while(cin >> n && n >= 0){
        int D, I;
        while (n--) {
            cin >> D >> I;
            int k = 1;
            for (int i = 0; i < D - 1; i++) {
                k *= 2;
                if (I % 2 == 0) k++;
                I = (I + 1) / 2;
            }
            cout << k << endl;
        }
    }
    return 0;
}
