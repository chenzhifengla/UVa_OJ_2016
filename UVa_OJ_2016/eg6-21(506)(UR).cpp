#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, int> name;
vector<vector<int> > depend;
vector<vector<int> > depend2;
vector<int> status;
vector<int> installed;

void install(int item, bool toplevel) {
	if (!status[item]) {
		for (int i = 0; i < depend[item].size(); i++) {
			install(depend[item][i], false);
		}
		cout << "   Installing " << name[item] << "\n";
		status[item] = toplevel ? 1 : 2;
		installed.push_back(item);
	}
}

bool needed(int item) {
	for (int i = 0; i < depend2[item].size(); i++) {
		if (status[depend2[item][i]]) return true;
	}
	return false;
}

void remove(int item, bool toplevel) {
	if ((toplevel || status[item] == 2) && !needed(item)) {
		status[item] = 0;
		installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
	}
}