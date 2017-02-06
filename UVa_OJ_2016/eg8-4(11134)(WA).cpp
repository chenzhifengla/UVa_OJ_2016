// 2017-02-06-chenkuan

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Range {
    int r1, r2, index;
    bool operator < (const Range& b) const {
        if (r1 != r2) return r1 < b.r1;
        else return r2 < b.r2;
    }
};
vector<Range> rangev, rangeh;

vector<int> getAns(vector<Range>& range) {
    sort(range.begin(), range.end());
    vector<int> ans(range.size(), 0);
    for (int i = 0; i < range.size(); i++) {
        if (!(range[i].r1 <= i + 1 && i + 1 <= range[i].r2)) return vector<int>();
        else ans[range[i].index] = i + 1;
    }
    return ans;
}

int main() {
#if LOCAL
    freopen("eg8-4(11134).in", "r", stdin);
#endif // LOCAL

    int n;
    while (cin >> n && n != 0) {
        rangev.assign(n, Range());
        rangeh.assign(n, Range());
        Range rv, rh;
        for (int i = 0; i < n; i++) {
            cin >> rv.r1 >> rh.r1 >> rv.r2 >> rh.r2;
            rv.index = rh.index = i;
            rangev[i] = rv;
            rangeh[i] = rh;
        }
        vector<int> ansv = getAns(rangev);
        vector<int> ansh = getAns(rangeh);
        if (ansv.empty() || ansh.empty()) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << ansv[i] << ' ' << ansh[i] << endl;
            }
        }
    }
    return 0;
}