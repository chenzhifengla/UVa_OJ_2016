#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

bool cmp1(const int& a, const int& b) {
	return a < b;
}

bool cmp2(const int& a, const int& b) {
	return a > b;
}

int main() {
	string a = "abc";
	if (a == "abc")printf("equal\n");
	return 0;
}