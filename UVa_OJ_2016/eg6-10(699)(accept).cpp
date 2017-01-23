//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int maxn = 1000 + 10;
//int sum[maxn];
//
//void build(int p) {
//	int v; cin >> v;
//	if (v == -1) return;
//	sum[p] += v;
//	build(p - 1); build(p + 1);
//}
//
//bool init() {
//	int v; cin >> v;
//	if (v == -1) return false;
//	memset(sum, 0, sizeof(sum));
//	int pos = maxn / 2;
//	sum[pos] = v;
//	build(pos - 1); build(pos + 1);
//}
//
//int main() {
//	int kase = 0;
//	while (init()) {
//		int p = 0;
//		while (sum[p] == 0) p++;
//		cout << "Case " << ++kase << ":\n" << sum[p++];
//		while (sump[p] != 0) cout << " " << sum[p++];
//	}
//	return 0;
//}


// 2017-01-23-chenkuan

#include <iostream>
#include <map>
using namespace std;
map<int, int> M;

bool readTree(int pos) {
    int root;
    cin >> root;
    if (root < 0) return false;
    if (M.find(pos) == M.end()) {
        M[pos] = root;
    }
    else M[pos] += root;
    readTree(pos - 1);
    readTree(pos + 1);
    return true;
}

int main() {
    //freopen("eg6-10(699).in", "r", stdin);
    int kase = 0;
    while (readTree(0)) {
        cout << "Case " << ++kase << ":" << endl;
        int num = 0;
        for (auto m : M) {
            if (num++) cout << ' ';
            cout << m.second;
        }
        cout << endl << endl;
        M.clear();
    }
    return 0;
}