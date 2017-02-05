// 2017-02-05-chenkuan

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("eg8-1(120).in", "r", stdin);
#endif // LOCAL

    string line;
    while (getline(cin, line)) {
        cout << line << endl;
        stringstream ss(line);
        int num;
        vector<int> v;
        while (ss >> num) {
            v.push_back(num);
        }
        reverse(v.begin(), v.end());

        for (auto start = v.begin(); start != v.end(); start++) {
            auto max = start;
            for (auto it = start; it != v.end(); it++) {
                if (*it > *max) {
                    max = it;
                }
            }
            if (max == start) continue;
            if (max < v.end() - 1) cout << max - v.begin() + 1 << ' ';
            reverse(max, v.end());
            if (start < v.end() - 1) cout << start - v.begin() + 1 << ' ';
            reverse(start, v.end());
        }
        cout << 0 << endl;
    }
    return 0;
}