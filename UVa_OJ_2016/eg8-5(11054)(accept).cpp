// 2017-02-09-chenkuan

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        long long ans = 0;
        int num, need = 0;
        while (n--) {
            cin >> num;
            ans += abs(need);
            need += num;
        }
        cout << ans << endl;
    }
    return 0;
}