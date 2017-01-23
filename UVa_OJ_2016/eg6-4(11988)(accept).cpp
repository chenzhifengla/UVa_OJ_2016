//#include <cstdio>
//#include <cstring>
//const int maxn = 100000 + 5;
//int last, cur, next[maxn];
//char s[maxn];
//
//int main() {
//	while (scanf("%s", s + 1) == 1) {
//		int n = strlen(s + 1);
//		last = cur = 0;
//		next[0] = 0;
//		for (int i = 1; i <= n; i++) {
//			char ch = s[i];
//			if (ch == '[') cur = 0;
//			else if (ch == ']') cur = last;
//			else {
//				next[i] = next[cur];
//				next[cur] = i;
//				if (cur == last) last = i;
//				cur = i;
//			}
//		}
//		for (int i = next[0]; i != 0; i = next[i]) {
//			printf("%c", s[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}


// 2017-01-22-chenkuan

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    //freopen("eg6-4(11988).in", "r", stdin);
    string s;
    while (cin >> s) {
        vector<int> next(s.length() + 1);
        next[0] = -1;
        int cur = 0, last = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                cur = 0;
            }
            else if (s[i] == ']') {
                cur = last;
            }
            else {
                next[i + 1] = next[cur];
                next[cur] = i + 1;
                if (cur == last) last = i + 1;
                cur = i + 1;
            }
        }
        for (int i = next[0]; i >= 0; i = next[i]) {
            cout << s[i - 1];
        }
        cout << endl;
    }
    return 0;
}