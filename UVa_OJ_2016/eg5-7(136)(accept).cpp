//#include <iostream>
//#include <vector>
//#include <queue>
//#include <set>
//#include <functional>
//
//using namespace std;
//typedef long long LL;
//const int coeff[3] = { 2, 3, 5 };
//
//int main() {
//	priority_queue<LL, vector<LL>, greater<LL> > pq;
//	set<LL> s;
//	pq.push(1);
//	s.insert(1);
//	for (int i = 1; ; i++) {
//		LL x = pq.top();
//		pq.pop();
//		if (i == 1500) {
//			cout << "The 1500'th ugly number is " << x << ".\n";
//			break;
//		}
//		for (int j = 0; j < 3; j++) {
//			LL x2 = x * coeff[j];
//			if (!s.count(x2)) {
//				s.insert(x2);
//				pq.push(x2);
//			}
//		}
//	}
//	return 0;
//}


// 2017-01-17-chenkaun

#include <iostream>
#include <queue>
#include <set>
#include <functional>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;
set<long long> s;

int main() {
    pq.push(1);
    s.insert(1);
    for (int i = 1; ; i++) {
        if (i == 1500) {
            cout << "The 1500'th ugly number is " << pq.top() << "." << endl;
            break;
        }
        long long num = pq.top(); pq.pop();
        int tmp[] = { 2, 3, 5 };
        for (int j = 0; j < 3; j++) {
            long long num_new = num * tmp[j];
            if (s.find(num_new) == s.end()) {
                s.insert(num_new);
                pq.push(num_new);
            }
        }
    }
    return 0;
}