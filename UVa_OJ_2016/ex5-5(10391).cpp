//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//using namespace std;
//
//map<char, vector<string> > dict;
//
//int main() {
//	for (char c = 'a'; c <= 'z'; c++) {
//		vector<string> v;
//		dict[c] = v;
//	}
//	string s;
//	while (cin >> s) {
//		dict[s[0]].push_back(s);
//	}
//}

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> dict;

int main() {
	string s;
	while (cin >> s) {
		dict[s] = 1;
	}
	for (map<string, int>::iterator it = dict.begin(); it != dict.end(); it++) {
		s = it->first;
		bool isCompound = false;
		for (int i = 1; i < s.length(); i++) {
			if (dict.count(s.substr(0, i)) && dict.count(s.substr(i))) {
				isCompound = true;
				break;
			}
		}
		if (isCompound) cout << s << endl;
	}
	return 0;
}