#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
using namespace std;

vector<string> para[101];
vector<string> paralower[101];
int paraNum;

string changeToLower(string s) {
	char line[1501];
	int i;
	for (i = 0; i < s.length(); i++) {
		line[i] = tolower(s[i]);
	}
	line[i] = '\0';
	string line2 = line;
	return line2;
}

bool queryInLine(string s, string line) {
	return line.find(s) != line.npos;
}

string queryInPara(string s, vector<string> para) {
	for (int i = 0; i < para.size(); i++) {
		if (queryInLine(s, para[i])) {
			return para[i];
		}
	}
	return "";
}

int main() {
	cin >> paraNum;
	for (int i = 0; i < paraNum; i++) {
		string line;
		while (getline(cin, line) && line != "**********") {
			para[i].push_back(line);
			paralower[i].push_back(changeToLower(line));
		}
	}
	int m;
	cin >> m;
	string line;
	getline(cin, line);
	while (m--) {
		getline(cin, line);
		stringstream ss(line);
		vector<string> cmd;
		string command;
		while (ss >> command) {
			cmd.push_back(command);
		}
		int allNum = 0;
		if (cmd.size() == 1) {
			for (int i = 0; i < paraNum; i++) {
				if (queryInPara(cmd[0], paralower[i]) == "") continue;
				for (int j = 0; j < paralower[i].size(); j++) {
					if (queryInLine(cmd[0], paralower[i][j])) {
						cout << para[i][j] << endl;
						allNum++;
					}
				}
				cout << "----------" << endl;
			}
		}
		else if (cmd.size() == 2) {
			for (int i = 0; i < paraNum; i++) {
				if (queryInPara(cmd[1], paralower[i]) != "") continue;
				allNum++;
				for (int j = 0; j < paralower[i].size(); j++) {
					cout << para[i][j] << endl;
				}
				cout << "----------" << endl;
			}
		}
		else if (cmd[1] == "AND") {
			for (int i = 0; i < paraNum; i++) {
				if (queryInPara(cmd[0], paralower[i]) == "" || queryInPara(cmd[2], paralower[i]) == "") {
					continue;
				}
				allNum++;
				for (int j = 0; j < paralower[i].size(); j++) {
					if (queryInLine(cmd[0], paralower[i][j]) || queryInLine(cmd[2], paralower[i][j])) {
						cout << para[i][j] << endl;
					}
				}
				cout << "----------" << endl;
			}
		}
		else if (cmd[1] == "OR") {
			for (int i = 0; i < paraNum; i++) {
				if (queryInPara(cmd[0], paralower[i]) == "" && queryInPara(cmd[2], paralower[i]) == "") {
					continue;
				}
				allNum++;
				for (int j = 0; j < paralower[i].size(); j++) {
					if (queryInLine(cmd[0], paralower[i][j]) || queryInLine(cmd[2], paralower[i][j])) {
						cout << para[i][j] << endl;
					}
				}
				cout << "----------" << endl;
			}
		}
		if (!allNum) {
			cout << "Sorry, I found nothing." << endl;
			cout << "----------" << endl;
		}
		cout << "----------" << endl;
	}
	return 0;
}