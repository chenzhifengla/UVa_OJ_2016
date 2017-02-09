// 2017-02-09-chenkuan

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("eg8-8(1471).in", "r", stdin);
#endif // LOCAL

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        vector<int> beg(n, 0);    // beg[i]为以第i个元素开头的最长递增序列长度
        vector<int> end(n, 0);    // end[i]为以第i个元素结尾的最长递增序列长度
        for (int i = 0, j = 0; j < n; ) {
            while (j < n && (j == i || v[j] > v[j - 1])) j++;
            while (i < j) {
                beg[i] = j - i;
                i++;
            }
        }
        for (int i = n - 1, j = n - 1; j >= 0; ) {
            while(j >= 0 && (j == i || v[j] < v[j + 1])) j--;
            while (i > j) {
                end[i] = i - j;
                i--;
            }
        }
        //for (auto num : beg) cout << num << ' '; cout << endl;
        //for (auto num : end) cout << num << ' '; cout << endl;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i && v[j] < v[i]; j++) {
                ans = max(ans, beg[i] + end[j]);
                //cout << "i = " << i << ", j = " << j << ", ans = " << beg[i] + end[j] << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}