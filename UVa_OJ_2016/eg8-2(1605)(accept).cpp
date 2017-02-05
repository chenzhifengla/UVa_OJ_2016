// 2017-02-05-chenkuan

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        cout << "2 " << n << " " << n << endl;
        string s(52, 0);
        for (int i = 0; i < 26; i++) {
            s[i] += 'A' + i;
            s[i + 26] += 'a' + i;
        }
        for (int i = 0; i < n; i++) {
            string line(n, s[i]);
            cout << line << endl;
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << s[j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}