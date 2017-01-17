//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//const int maxcol = 60;
//const int maxn = 100 + 5;
//string filenames[maxn];
//
//void print(const string& s, int len, char extra) {
//	cout << s;
//	for (int i = 0; i < len - s.length(); i++) {
//		cout << extra;
//	}
//}
//
//int main() {
//	int n;
//	while (cin >> n) {
//		int M = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> filenames[i];
//			M = max(M, (int)filenames[i].length());
//		}
//		int cols = (maxcol - M) / (M + 2) + 1, rows = (n - 1) / cols + 1;
//		print("", 60, '-');
//		cout << "\n";
//		sort(filenames, filenames + n);
//		for (int r = 0; r < rows; r++) {
//			for (int c = 0; c < cols; c++) {
//				int idx = c * rows + r;
//				if (idx < n) print(filenames[idx], c == cols - 1 ? M : M + 2, ' ');
//			}
//			cout << "\n";
//		}
//	}
//	return 0;
//}


// 2017-01-17-chenkuan

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<string> V;

int main() {
    //freopen("eg5-8(400).in", "r", stdin);
    while (cin >> n) {
        V.clear();
        int maxlen = 0;
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            V.push_back(s);
            maxlen = max(maxlen, (int)s.length());
        }
        sort(V.begin(), V.end());
        int colnum = 62 / (maxlen + 2);
        int rownum = (n - 1) / colnum + 1;
        string _(60, '-');
        cout << _ << endl;
        for (int i = 0; i < rownum; i++) {
            for (int j = 0; j < colnum; j++) {
                int index = j * rownum + i;
                if (index < V.size()) {
                    cout << V[index];
                    int len = maxlen - V[index].length();
                    if (j == colnum - 1) _ = string(len, ' ');
                    else _ = string(len + 2, ' ');
                    cout << _;
                }
            }
            cout << endl;
        }
    }
    return 0;
}