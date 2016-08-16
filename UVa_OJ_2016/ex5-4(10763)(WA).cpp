//#include <iostream>
//#include <map>
//using namespace std;
//map<int, int> stu;
//
//int main() {
//	int n;
//	while (scanf("%d", &n) != EOF && n) {
//		stu.clear();
//		for (int i = 0; i < n; i++) {
//			int a, b;
//			scanf("%d%d", &a, &b);
//			stu[a] = b;
//		}
//		bool couldExchange = true;
//		for (map<int, int>::iterator it = stu.begin(); it != stu.end(); it++) {
//			int b = it->second;
//			if (stu.find(b) == stu.end()) {
//				couldExchange = false;
//				break;
//			}
//		}
//		if (couldExchange) printf("YES\n");
//		else printf("NO\n");
//	}
//	return 0;
//}

#include <iostream>
#include <map>
using namespace std;
struct student {
	int a, b;
	bool operator < (const student& b) const {
		if (this->a == b.a) return this->a < b.a;
		else return this->a < b.a;
	}
};
map<student, int> stu;

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n) {
		stu.clear();
		for (int i = 0; i < n; i++) {
			student s, sr;
			scanf("%d%d", &s.a, &s.b);
			sr.a = s.b;
			sr.b = s.a;
			if (stu.count(sr)) {
				stu[sr]--;
				if (stu[sr] == 0) {
					stu.erase(sr);
				}
			}
			else if (stu.count(s))	stu[s]++;
			else stu[s] = 1;
		}
		if (stu.empty()) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}