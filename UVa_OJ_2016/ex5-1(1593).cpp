#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

const int maxn = 1001;
vector<string> words[maxn];
vector<int> maxlen;

int main() {
	string line;
	int lineNum = 0;
	while (getline(cin, line)) {
		stringstream ss(line);
		string word;
		int wordNum = 0;
		while (ss >> word) {
			words[lineNum].push_back(word);
			if (maxlen.size() <= word.length()) {
				maxlen.push_back(word.length());
			}
			else if (word.length() > maxlen[wordNum]) {
				maxlen[wordNum] = word.length();
			}
			wordNum++;
		}
		lineNum++;
	}
	for (int i = 0; i < lineNum; i++) {
		for (int j = 0; j < words[i].size() - 1; j++) {
			int len = maxlen[j] + 1;
			printf("%s", words[i][j].c_str());
			for (int k = 0; k < len - words[i][j].length(); k++) {
				printf(" ");
			}
		}
		printf("%s\n", words[i][words[i].size() - 1].c_str());
	}
	return 0;
}