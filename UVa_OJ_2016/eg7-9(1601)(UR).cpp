// 2017-02-04-chenkuan

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <set>
using namespace std;
struct Point {
    int x, y;
    Point(int x = -1, int y = -1) :x(x), y(y) {}
};
vector<Point> blanks;   // 记录所有的空白点
vector<vector<int>> blank_num;  // 根据xy坐标查找其在blanks中坐标，不是空白点初值为-1
vector<vector<int>> G_blank;   // 记录每一个空白点相连的其他所有空白点
vector<string> G;   // 原图
struct State {
    vector<int> pos;
    int dist;
    bool operator < (const State& b) const {
        return pos < b.pos;
    }
};
State source, dest; // 起点和终点们
set<State> vis;   // 访问控制

int main() {
    int r, c, n;
    while (cin >> r >> c >> n && r != 0) {
        G.clear();
        string line;
        for (int i = 0; i < r; i++) {
            getline(cin, line);
            line.append(' ', c - line.size());
            G.push_back(line);
        }
        blanks.clear();
        blank_num.assign(r, vector<int>(c, -1));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (G[i][j] != '#') {
                    blanks.emplace_back(i, j);
                    blank_num[i][j] = blanks.size() - 1;
                }
            }
        }
        
        G_blank.assign(blanks.size(), vector<int>());
        source.pos.assign(n, -1);
        dest.pos.assign(n, -1);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int thisp;
                if (G[i][j] == '#') continue;
                else {
                    thisp = blank_num[i][j];
                    // 判断右边是不是空白点
                    if (j + 1 < c && G[i][j + 1] != '#') {
                        int nextp = blank_num[i][j + 1];
                        G_blank[thisp].push_back(nextp);
                    }
                    // 判断下边是不是空白点
                    if (i + 1 < r && G[i + 1][j] != '#') {
                        int nextp = blank_num[i + 1][j];
                        G_blank[thisp].push_back(nextp);
                    }
                }
                if (isupper(G[i][j])){
                    dest.pos[G[i][j] - 'A'] = thisp;
                }
                else if (islower(G[i][j])) {
                    source.pos[G[i][j] - 'a'] = thisp;
                }
            }
        }
        
        source.dist = 0;
        queue<State> q;
        q.push(source);
        while (!q.empty()) {
            State state = q.front();
            q.pop();
            if (state.pos == dest.pos) {
                cout << state.dist << endl;
                break;
            }
            State s1 = state;
            for (int i = 0; i < n; i++) {
                for (int neibor : G_blank[state.pos[i]]) {

                }
            }
            for (int index : state.pos) {
                for (int neibor : G_blank[index]) {
                    s1.pos
                }
            }
        }
    }
}