// 2017-02-05-chenkuan

#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, int> M;
vector<int> V[4];

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
            v.clear();
        }
        int num;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &num);
                V[j].push_back(num);
            }
        }
        M.clear();
        for (auto a : V[0]){
            for (auto b : V[1]) {
                int sum = a + b;
                if (M.find(sum) == M.end()) {
                    M[sum] = 1;
                }
                else M[sum]++;
            }
        }
        int ans = 0;
        for (auto c : V[2]) {
            for (auto d : V[3]) {
                int sum = 0 - c - d;
                if (M.find(sum) != M.end()) {
                    ans += M[sum];
                }
            }
        }
        if (t) cout << endl;
        cout << ans << endl;
    }
}