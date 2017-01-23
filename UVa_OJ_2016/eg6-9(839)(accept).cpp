//#include <iostream>
//using namespace std;
//
//bool solve(int& W) {
//	int W1, D1, W2, D2;
//	bool b1 = true, b2 = true;
//	cin >> W1 >> D1 >> W2 >> D2;
//	if (!W1) b1 = solve(W1);
//	if (!W2) b2 = solve(W2);
//	W = W1 + W2;
//	return b1 && b2 && (W1 * D1 == W2 * D2);
//}
//
//int main() {
//	int T, W;
//	cin >> T;
//	while (T--) {
//		if (solve(W)) cout << "YES\n"; else cout << "NO\n";
//		if (T) cout << "\n";
//	}
//	return 0;
//}


// 2017-01-23-chenkuan

#include <iostream>
using namespace std;

pair<bool, int> isBalanced() {
    int wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;
    pair<bool, int> bwl(true, wl), bwr(true, wr);
    if (wl == 0) bwl = isBalanced();
    if (wr == 0) bwr = isBalanced();
    if (!bwl.first || !bwr.first) return{ false, 0 };
    return{ bwl.second * dl == bwr.second * dr, bwl.second + bwr.second };
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        if (isBalanced().first) cout << "YES" << endl;
        else cout << "NO" << endl;
        if (t) cout << endl;
    }
    return 0;
}