//#include <iostream>
//#include <set>
//#include <map>
//#include <vector>
//#include <stack>
//#include <string>
//#include <algorithm>
//#include <iterator>
//#define ALL(x) x.begin(),x.end()
//#define INS(x) inserter(x,x.begin())
//
//using namespace std;
//typedef set<int> Set;
//map<Set, int> IDcache;
//vector<Set> Setcache;
//
//int ID(Set x) {
//	if (IDcache.count(x)) return IDcache[x];
//	Setcache.push_back(x);
//	return IDcache[x] = Setcache.size() - 1;
//}
//
//int main() {
//	int kase;
//	scanf("%d", &kase);
//	while (kase--) {
//		stack<int> s;
//		int n;
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			string op;
//			cin >> op;
//			if (op[0] == 'P') s.push(ID(Set()));
//			else if (op[0] == 'D') s.push(s.top());
//			else {
//				Set x1 = Setcache[s.top()];
//				s.pop();
//				Set x2 = Setcache[s.top()];
//				s.pop();
//				Set x;
//				if (op[0] == 'U') {
//					std::set_union(ALL(x1), ALL(x2), INS(x));
//				}
//				else if (op[0] == 'I') {
//					set_intersection(ALL(x1), ALL(x2), INS(x));
//				}
//				else if (op[0] == 'A') {
//					x = x2;
//					x.insert(ID(x1));
//				}
//				s.push(ID(x));
//			}
//			cout << Setcache[s.top()].size() << endl;
//		}
//		cout << "***" << endl;
//	}
//	return 0;
//}


// 2017-01-17-chenkuan

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
int t, n;
stack<int> S;
map<set<int>, int> set_to_id;
map<int, set<int>> id_to_set;

int getSetId(set<int> s) {
    if (set_to_id.find(s) == set_to_id.end()) {
        int id = id_to_set.size();
        set_to_id[s] = id;
        id_to_set[id] = s;
    }
    return set_to_id[s];
}

set<int> getIdSet(int id) {
    return id_to_set[id];
}

int main() {
    //freopen("eg5-5(12096).in", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        while (!S.empty()) S.pop();
        set_to_id.clear();
        id_to_set.clear();
        while (n--) {
            string cmd;
            cin >> cmd;
            if (cmd == "PUSH") {
                S.push(getSetId(set<int>()));
            }
            else if (cmd == "DUP") {
                S.push(S.top());
            }
            else {
                set<int> s1 = getIdSet(S.top()); S.pop();
                set<int> s2 = getIdSet(S.top()); S.pop();
                set<int> s_new; s_new.clear();
                if (cmd == "UNION") {
                    set_union(s1.begin(), s1.end(),
                        s2.begin(), s2.end(), inserter(s_new, s_new.begin()));
                }
                else if (cmd == "INTERSECT") {
                    set_intersection(s1.begin(), s1.end(), 
                        s2.begin(), s2.end(), inserter(s_new, s_new.begin()));
                }
                else if (cmd == "ADD") {
                    s2.insert(getSetId(s1));
                    s_new = s2;
                }
                S.push(getSetId(s_new));
            }
            cout << getIdSet(S.top()).size() << endl; 
        }
        cout << "***" << endl;
    }
    return 0;
}