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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> V[4];
vector<int> sum;

//int findNum(int num) {
//    auto first = sum.begin(), last = sum.end();
//    auto mid = sum.begin();
//    while (first < last) {
//        mid = first + (last - first) / 2;
//        if (*mid == num) break;
//        else if (*mid > num) {
//            last = mid;
//        }
//        else {
//            first = mid + 1;
//        }
//    }
//    int ans = 0;
//    for (auto index = mid; index != sum.end() && *index == num; index++, ans++);
//    auto index = mid;
//    while (index != sum.begin()) {
//        if (*(--index) == num) ans++;
//    }
//    return ans;
//}

int findNum(int num) {
    int first = 0, last = sum.size(), mid = 0;
    while (first < last) {
        mid = first + (last - first) / 2;
        if (sum[mid] == num) break;
        else if (sum[mid] > num) {
            last = mid;
        }
        else {
            first = mid + 1;
        }
    }
    int ans = 0;
    for (int index = mid; index != sum.size() && sum[index] == num; index++, ans++);
    while (mid != 0) {
        if (sum[--mid] == num) ans++;
    }
    return ans;
}

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
                //sum.push_back(a + b);
                sum[index++] = a + b;
            }
        }
        sort(sum.begin(), sum.end());
        int ans = 0;
        for (auto& c : V[2]) {
            for (auto& d : V[3]) {
                num = 0 - c - d;
                ans += findNum(num);
            }
        }
        cout << ans << endl;
    }
    return 0;
}