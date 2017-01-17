//#include <cstdio>
//#include <queue>
//#include <map>
//using namespace std;
//
//const int maxt = 1000 + 10;
//
//int main() {
//	int t, kase = 0;
//	while (scanf("%d", &t) == 1 && t) {
//		printf("Scenario #%d\n", ++kase);
//		map<int, int> team;
//		for (int i = 0; i < t; i++) {
//			int n, x;
//			scanf("%d", &n);
//			while (n--) {
//				scanf("%d", &x);
//				team[x] = i;
//			}
//		}
//		queue<int> q, q2[maxt];
//		for (;;) {
//			int x;
//			char cmd[10];
//			scanf("%s", cmd);
//			if (cmd[0] == 'S') break;
//			else if (cmd[0] == 'D') {
//				int t = q.front();
//				printf("%d\n", q2[t].front());
//				q2[t].pop();
//				if (q2[t].empty()) {
//					q.pop();
//				}
//			}
//			else if (cmd[0] == 'E') {
//				scanf("%d", &x);
//				int t = team[x];
//				if (q2[t].empty()) {
//					q.push(t);
//				}
//				q2[t].push(x);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}


// 2017-01-17-chenkuan

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
using namespace std;
queue<int> teams;    // 团队号的队列
vector<queue<int>> V;   // 各团队内部人员队列
map<int, int> M;    // 人员编号到团队编号的映射

int main() {
    //freopen("eg5-6(540).in", "r", stdin);
    int t, kase = 0;
    while (cin >> t) {
        if (t == 0) break;
        cout << "Scenario #" << ++kase << endl;
        while (!teams.empty()) teams.pop();
        V.clear();
        for (int i = 0; i < t; i++) {
            V.push_back(queue<int>());
            int num;
            cin >> num;
            for (int j = 0; j < num; j++) {
                int person;
                cin >> person;
                M[person] = i;
            }
        }
        string cmd;
        while (cin >> cmd) {
            if (cmd == "STOP") break;
            else if (cmd == "ENQUEUE") {
                int person;
                cin >> person;
                int team = M[person];
                if (V[team].empty()) {
                    teams.push(team);
                }
                V[team].push(person);
            }
            else if (cmd == "DEQUEUE") {
                int team = teams.front();
                cout << V[team].front() << endl;
                V[team].pop();
                if (V[team].empty()) {
                    teams.pop();
                }
            }
        }
        cout << endl;
    }
    return 0;
}