#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<string, string> olddict;
map<string, string> newdict;
vector<string> addkey;
vector<string> delkey;
vector<string> modkey;

map<string, string> split(string line) {
	map<string, string> dict;
	line = line.substr(1);
	for (;;) {
		int colonIndex = line.find(':');
		if (colonIndex == line.npos) break;
		string key = line.substr(0, colonIndex);
		line = line.substr(colonIndex + 1);

		int commaIndex = line.find(',');
		if (commaIndex == line.npos) commaIndex = line.length() - 1;
		string value = line.substr(0, commaIndex);
		line = line.substr(commaIndex + 1);

		dict[key] = value;
	}
	return dict;
}

void print(char c, vector<string> k) {
	cout << c << k[0];
	for (int i = 1; i < k.size(); i++) {
		cout << "," << k[i];
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string oldstring, newstring;
		cin >> oldstring >> newstring;
		addkey.clear();
		delkey.clear();
		modkey.clear();
		olddict = split(oldstring);
		newdict = split(newstring);
		for (map<string, string>::iterator it = olddict.begin(); it != olddict.end(); it++) {
			if (!newdict.count(it->first)) {
				delkey.push_back(it->first);
			}
			else if (it->second != newdict[it->first]) {
				modkey.push_back(it->first);
			}
		}
		for (map<string, string>::iterator it = newdict.begin(); it != newdict.end(); it++) {
			if (!olddict.count(it->first)) {
				addkey.push_back(it->first);
			}
		}
		if (!addkey.size() && !delkey.size() && !modkey.size()) {
			cout << "No changes" << endl;
		}
		else {
			if (addkey.size()) {
				print('+', addkey);
			}
			if (delkey.size()) {
				print('-', delkey);
			}
			if (modkey.size()) {
				print('*', modkey);
			}	
		}
		cout << endl;
	}
	return 0;
}