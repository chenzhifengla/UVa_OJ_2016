#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp1(const int& a, const int& b) {
	return a < b;
}

bool cmp2(const int& a, const int& b) {
	return a > b;
}

int main() {
	int buf[] = { 4, 6, 2, 8, 5 };
	sort(buf, buf + 5, cmp1);
	sort(buf, buf + 5, cmp2);
	return 0;
}