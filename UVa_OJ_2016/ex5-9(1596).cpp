#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

struct Array {
	int len;
	map<int, int> value;
};
map<string, Array> arrays;
bool haserror;

int getValue(string s) {
	int leftindex = s.find('[');
	if (leftindex == s.npos) {
		stringstream ss(s);
		int value;
		ss >> value;
		return value;
	}
	else {
		int rightindex = s.rfind(']');
		string name = s.substr(0, leftindex);
		int value = getValue(s.substr(leftindex + 1, rightindex - leftindex - 1));
		if (haserror) {
			return -1;
		}
		else if(value < 0 || value >= arrays[name].len || !arrays[name].value.count(value)){
			haserror = true;
			return -1;
		}
		else return arrays[name].value[value];
	}
}

int main() {
	string line;
	while (cin >> line && line != ".") {
		int lineNum = 1;
		bool hasBug = false;
		int bugLine;
		do {
			int equalindex;
			if ((equalindex = line.find('=')) == line.npos) {
				int leftindex = line.find('[');
				string name = line.substr(0, leftindex);
				int value = getValue(line.substr(leftindex + 1, line.length() - leftindex - 2));
				if (haserror || value < 0) {
					if (!hasBug) bugLine = lineNum;
					hasBug = true;
					haserror = false;
				}
				else {
					Array a;
					a.len = value;
					arrays[name] = a;
				}
			}
			else {
				int value = getValue(line.substr(equalindex + 1, line.length() - equalindex - 1));
				if (haserror) {
					if (!hasBug) bugLine = lineNum;
					hasBug = true;
					haserror = false;
				}
				else {
					int leftindex = line.find('[');
					int rightindex = line.rfind(']', equalindex);
					string name = line.substr(0, leftindex);
					int value2 = getValue(line.substr(leftindex + 1, rightindex - leftindex - 1));
					if (haserror || value2 < 0 || arrays[name].len <= value2) {
						if (!hasBug) bugLine = lineNum;
						hasBug = true;
						haserror = false;
					}
					else {
						arrays[name].value[value2] = value;
					}
				}
			}
			cin >> line;
			lineNum++;
		} while (line != ".");
		if (hasBug) {
			cout << bugLine << endl;
		}
		else cout << "0" << endl;
	}
	return 0;
}