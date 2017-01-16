//#include <iostream>
//#include <string>
//#include <set>
//#include <sstream>
//using namespace std;
//
//set<string> dict;
//
//int main() {
//	string s, buf;
//	while (cin >> s) {
//		for (int i = 0; i < s.length(); i++) {
//			if (isalpha(s[i])) s[i] = tolower(s[i]);
//			else s[i] = ' ';
//		}
//		stringstream ss(s);
//		while (ss >> buf)	dict.insert(buf);
//	}
//	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
//		cout << *it << "\n";
//	}
//	return 0;
//}


// 2017-01-16-chenkuan

#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;
set<string> dict;

int main() {
    string st, s;
    while (cin >> st) {
        for (auto &c : st) {
            if (isalpha(c)) {
                c = tolower(c);
            }
            else {
                c = ' ';
            }
        }
        stringstream ss(st);
        while (ss >> s) {
            dict.insert(s);
        }
    }
    for (auto s : dict) {
        cout << s << endl;
    }
    return 0;
}