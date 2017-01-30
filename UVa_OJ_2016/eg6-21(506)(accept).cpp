//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//map<string, int> name;
//vector<vector<int> > depend;
//vector<vector<int> > depend2;
//vector<int> status;
//vector<int> installed;
//
//void install(int item, bool toplevel) {
//	if (!status[item]) {
//		for (int i = 0; i < depend[item].size(); i++) {
//			install(depend[item][i], false);
//		}
//		cout << "   Installing " << name[item] << "\n";
//		status[item] = toplevel ? 1 : 2;
//		installed.push_back(item);
//	}
//}
//
//bool needed(int item) {
//	for (int i = 0; i < depend2[item].size(); i++) {
//		if (status[depend2[item][i]]) return true;
//	}
//	return false;
//}
//
//void remove(int item, bool toplevel) {
//	if ((toplevel || status[item] == 2) && !needed(item)) {
//		status[item] = 0;
//		installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
//	}
//}


// 2017-01-30-chenkuan

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
using namespace std;
vector<string> names;
map<string, int> ID;
vector<vector<int>> depend1;    // 组件x所依赖的组件
vector<vector<int>> depend2;    // 依赖于组件x的组件
vector<int> status;    // 0是未安装，1是显示安装的，2是隐式安装的
vector<int> installed;

int getID(string s) {
    if (ID.count(s) == 0) {
        ID[s] = (int)names.size();
        names.push_back(s);
        depend1.push_back(vector<int>());
        depend2.push_back(vector<int>());
        status.push_back(false);
    }
    return ID[s];
}

void install(int item, bool toplevel) {
    if (status[item] == 0) {
        for (auto item1 : depend1[item]) {
            install(item1, false);
        }
        cout << "   Installing " << names[item] << endl;
        status[item] = toplevel ? 1 : 2;
        installed.push_back(item);
    }
    else if (toplevel){
        cout << "   " << names[item] << " is already installed." << endl;
    }
}

bool need(int item) {
    for (int item1 : depend2[item]) {
        if (status[item1]) return true;
    }
    return false;
}

void remove(int item, bool toplevel) {
    if (toplevel && status[item] == 0) {
        cout << "   " << names[item] << " is not installed." << endl;
        return;
    }
    if (toplevel && need(item)) {
        cout << "   " << names[item] << " is still needed." << endl;
        return;
    }
    if ((toplevel || status[item] == 2) && need(item) == false) {
        status[item] = 0;
        installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
        cout << "   Removing " << names[item] << endl;
        for (auto item1 : depend1[item]) {
            remove(item1, false);
        }
    }
}

void list() {
    for (int item : installed) {
        cout << "   " << names[item] << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("eg6-21(506).in", "r", stdin);
#endif // LOCAL

    string s;
    while (getline(cin, s)) {
        names.clear();
        ID.clear();
        depend1.clear();
        depend2.clear();
        status.clear();
        installed.clear();
        do {
            cout << s << endl;
            stringstream ss(s);
            ss >> s;
            if (s == "DEPEND") {
                ss >> s;
                int item = getID(s);
                while (ss >> s) {
                    int item2 = getID(s);
                    depend1[item].push_back(item2);
                    depend2[item2].push_back(item);
                }
            }
            else if (s == "INSTALL") {
                ss >> s;
                install(getID(s), true);
            }
            else if (s == "REMOVE") {
                ss >> s;
                remove(getID(s), true);
            }
            else if (s == "LIST") {
                list();
            }
            else if (s == "END") {
                break;
            }
        } while (getline(cin, s));
    }
    return 0;
}