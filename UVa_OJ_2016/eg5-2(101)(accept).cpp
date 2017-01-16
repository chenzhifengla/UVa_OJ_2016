//#include <cstdio>
//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//const int maxn = 30;
//int n;
//vector<int> pile[maxn];
//
//void find_block(int a, int& p, int& h) {
//	for (p = 0; p < n; p++) {
//		for (h = 0; h < pile[p].size(); h++) {
//			if (pile[p][h] == a) return;
//		}
//	}
//}
//
//void clear_above(int p, int h) {
//	for (int i = h + 1; i < pile[p].size(); i++) {
//		int b = pile[p][i];
//		pile[b].push_back(b);
//	}
//	pile[p].resize(h + 1);
//}
//
//void pile_onto(int p, int h, int p2) {
//	for (int i = h; i < pile[p].size(); i++) {
//		pile[p2].push_back(pile[p][i]);
//	}
//	pile[p].resize(h);
//}
//
//void print() {
//	for (int i = 0; i < n; i++) {
//		printf("%d:", i);
//		for (int j = 0; j < pile[i].size(); j++) {
//			printf(" %d", pile[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main() {
//	int a, b;
//	cin >> n;
//	string s1, s2;
//	for (int i = 0; i < n; i++) pile[i].push_back(i);
//	while (cin >> s1 && s1 != "quit") {
//		cin >> a >> s2 >> b;
//		int pa, pb, ha, hb;
//		find_block(a, pa, ha);
//		find_block(b, pb, hb);
//		if (pa == pb) continue;
//		if (s2 == "onto") clear_above(pb, hb);
//		if (s1 == "move") clear_above(pa, ha);
//		pile_onto(pa, ha, pb);
//	}
//	print();
//	return 0;
//}


//2017-01-16-chenkuan

#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int maxn = 30;
vector<int> pile[maxn];
int n;

pair<vector<int>*, vector<int>::iterator> find_num(int num) {
    for (auto p = begin(pile); p != end(pile); p++) {
        for (auto it = p->begin(); it != p->end(); it++) {
            if (*it == num) {
                return make_pair(p, it);
            }
        }
    }
}

void back(int num) {
    auto pos = find_num(num);
    while (pos.first->end() - 1 != pos.second) {
        auto back_num = pos.first->back();
        pile[back_num].push_back(back_num);
        pos.first->pop_back();
    }
}

void move(pair<vector<int>*, vector<int>::iterator> pos_a, pair<vector<int>*, vector<int>::iterator> pos_b) {
    while (pos_a.second != pos_a.first->end()) {
        pos_b.first->push_back(*pos_a.second);
        pos_a.second = pos_a.first->erase(pos_a.second);
    }
}

int main() {
    //freopen("eg5-2(101).in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        pile[i].push_back(i);
    }
    string cmd1, cmd2;
    int a, b;
    while (cin >> cmd1) {
        if (cmd1 == "quit") break;
        cin >> a >> cmd2 >> b;
        auto pos_a = find_num(a);
        auto pos_b = find_num(b);
        if (pos_a.first == pos_b.first) continue;
        if (cmd1 == "move") {
            back(a);
        }
        if (cmd2 == "onto") {
            back(b);
        }
        move(pos_a, pos_b);
    }
    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (auto num : pile[i]) {
            cout << " " << num;
        }
        cout << endl;
    }
}