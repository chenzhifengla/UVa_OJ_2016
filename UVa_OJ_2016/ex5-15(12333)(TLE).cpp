#include <iostream>
#include <vector>
#include <cstring>
#include <assert.h>
using namespace std;


struct BigInteger {
	vector<int> s;
	BigInteger(long long num = 0) { s.clear(); };
	BigInteger operator + (const BigInteger& b) const {
		BigInteger c;
		int carry = 0, num = 0;
		for (int i = 0; i < this->s.size() && i < b.s.size(); i++) {
			num = this->s[i] + b.s[i] + carry;
			carry = num / 10;
			c.s.push_back(num % 10);
		}
		if (this->s.size() > b.s.size()) {
			for (int i = b.s.size(); i < this->s.size(); i++) {
				num = this->s[i] + carry;
				carry = num / 10;
				c.s.push_back(num % 10);
			}
		}
		else {
			for (int i = this->s.size(); i < b.s.size(); i++) {
				num = b.s.size() + carry;
				carry = num / 10;
				c.s.push_back(num % 10);
			}
		}
		assert(carry < 10);
		if (carry) {
			c.s.push_back(carry);
		}
		return c;
	}
};

const int maxn = 10000;
BigInteger fib[maxn];

void init() {
	fib[0].s.push_back(1);
	fib[1].s.push_back(1);
	for (int i = 2; i < maxn; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
}

bool isSubStr(char input[], int len, int index) {
	int size = fib[index].s.size();
	for (int i = 0; i < len; i++) {
		if (input[i] != fib[index].s[size - i - 1]) return false;
	}
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	init();
	char input[41];
	for (int i = 0; i < t; i++) {
		printf("Case #%d: ", i);
		scanf("%s", input);
		int len = strlen(input);
		for (int i = 0; i < len; i++) {
			input[i] -= '0';
		}
		int index;
		for(index = 0; index < maxn; index++) {
			if (len > fib[index].s.size()) continue;
			if (isSubStr(input, len, index)) break;
		}
		if (index >= maxn) printf("-1\n");
		else printf("%d\n", index);
	}
	return 0;
}