#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;

stack<char> s;
string buf;

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	while (n--) {
		while (!s.empty()) s.pop();
		getline(cin, buf);
		bool could = true;
		for (int i = 0; i < buf.length(); i++) {
			if (buf[i] == '(' || buf[i] == '[') {
				s.push(buf[i]);
			}
			else if (s.empty()) {
				could = false;
				break;
			}
			else if ((s.top() == '[' && buf[i] == ']') || (s.top() == '(' && buf[i] == ')')) {
				s.pop();
			}
			else {
				could = false;
				break;
			}
		}
		if (could && s.empty()) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}