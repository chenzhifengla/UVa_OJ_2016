//#include <iostream>
//#include <string>
//#include <cctype>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//map<string, int> cnt;
//vector<string> words;
//
//string repr(const string& s) {
//	string ans = s;
//	for (int i = 0; i < ans.length(); i++) {
//		ans[i] = tolower(ans[i]);
//	}
//	sort(ans.begin(), ans.end());
//	return ans;
//}
//
//int main() {
//	int n = 0;
//	string s;
//	while (cin >> s) {
//		if (s[0] == '#') break;
//		words.push_back(s);
//		string r = repr(s);
//		if (!cnt.count(r)) cnt[r] = 0;
//		cnt[r]++;
//	}
//	vector<string> ans;
//	for (int i = 0; i < words.size(); i++) {
//		if (cnt[repr(words[i])] == 1) {
//			ans.push_back(words[i]);
//		}
//	}
//	sort(ans.begin(), ans.end());
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << "\n";
//	}
//	return 0;
//}


// 2017-01-16-chenkuan

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
map<string, int> maps;
vector<string> words;

string lower(string s) {
    for (auto &c : s) {
        c = tolower(c);
    }
    sort(s.begin(), s.end());
    return s;
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "#") break;
        words.push_back(s);
        s = lower(s);
        if (maps.find(s) != maps.end()) {
            maps[s]++;
        }
        else {
            maps[s] = 1;
        }
    }
    sort(words.begin(), words.end());
    for (auto s : words) {
        if (maps[lower(s)] == 1) {
            cout << s << endl;
        }
    }
    return 0;
}