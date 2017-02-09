//// 2017-02-05-chenkuan
//// 直接使用map超时
//#include <iostream>
//#include <map>
//#include <vector>
//using namespace std;
//map<int, int> M;
//vector<int> V[4];
//
//int main() {
//#ifdef LOCAL
//    freopen("eg8-3(1152).in", "r", stdin);
//#endif // LOCAL
//
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        for (auto& v : V) {
//            v.clear();
//        }
//        int num;
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < 4; j++) {
//                scanf("%d", &num);
//                V[j].push_back(num);
//            }
//        }
//        M.clear();
//        for (auto a : V[0]){
//            for (auto b : V[1]) {
//                int sum = a + b;
//                if (M.find(sum) == M.end()) {
//                    M[sum] = 1;
//                }
//                else M[sum]++;
//            }
//        }
//        int ans = 0;
//        for (auto c : V[2]) {
//            for (auto d : V[3]) {
//                int sum = 0 - c - d;
//                if (M.find(sum) != M.end()) {
//                    ans += M[sum];
//                }
//            }
//        }
//        if (t) cout << endl;
//        cout << ans << endl;
//    }
//}


// 2017-02-06-chenkuan
// 尝试使用数组存储并排序，然后使用二分查找
// 还是超时
// 改成STL的range函数二分查找不超时了

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> V[4];
vector<int> sum;

int main() {
#ifdef LOCAL
    freopen("eg8-3(1152).in", "r", stdin);
#endif // LOCAL

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (auto& v : V) {
            v.assign(n, 0);
        }
        int num;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &num);
                V[j][i] = num;
            }
        }
        sum.assign(n * n, 0);
        int index = 0;
        for (auto& a : V[0]) {
            for (auto& b : V[1]) {
                sum[index++] = a + b;
            }
        }
        sort(sum.begin(), sum.end());
        int ans = 0;
        for (auto& c : V[2]) {
            for (auto& d : V[3]) {
                num = 0 - c - d;
                auto range = equal_range(sum.begin(), sum.end(), num);
                ans += range.second - range.first;
            }
        }
        cout << ans << endl;
        if (t) cout << endl;
    }
    return 0;
}