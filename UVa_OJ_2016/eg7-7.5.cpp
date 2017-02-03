//#include <stdio.h>
//#include <string.h>
//
//typedef int State[9];
//const int maxstate = 1000000;
//State st[maxstate], goal;
//int dist[maxstate];
//
//const int dx[] = { -1, 1, 0, 0 };
//const int dy[] = { 0, 0, -1, 1 };
//
//int vis[362880], fact[9];
//void init_lookup_table() {
//	fact[0] = 1;
//	for (int i = 1; i < 9; i++) {
//		fact[i] = fact[i - 1] * i;
//	}
//}
//
//int try_to_insert(int s) {
//	int code = 0;
//	for (int i = 0; i < 9; i++) {
//		int cnt = 0;
//		for (int j = i + 1; j < 9; j++) {
//			if (st[s][j] < st[s][i]) cnt++;
//		}
//		code += fact[8 - i] * cnt;
//	}
//	if (vis[code]) return 0;
//	return vis[code] = 1;
//}
//
//int bfs() {
//	init_lookup_table();
//	int front = 1, rear = 2;
//	while (front < rear) {
//		State& s = st[front];
//		if (memcmp(goal, s, sizeof(s)) == 0) return front;
//		int z;
//		for (z = 0; z < 9; z++) {
//			if (!s[z]) break;
//		}
//		int x = z / 3, y = z % 3;
//		for (int d = 0; d < 4; d++) {
//			int newx = x + dx[d];
//			int newy = y + dy[d];
//			int newz = newx * 3 + newy;
//			if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
//				State& t = st[rear];
//				memcpy(&t, &s, sizeof(s));
//				t[newz] = s[z];
//				t[z] = s[newz];
//				dist[rear] = dist[front] + 1;
//				if (try_to_insert(rear)) rear++;
//			}
//		}
//		front++;
//	}
//	return 0; 
//}
//
//int main() {
//	for (int i = 0; i < 9; i++) {
//		scanf("%d", &st[1][i]);
//	}
//	for (int i = 0; i < 9; i++) {
//		scanf("%d", &goal[i]);
//	}
//	int ans = bfs();
//	if (ans > 0) printf("%d\n", dist[ans]);
//	else printf("-1\n");
//	return 0;
//}


// 2017-02-03-chenkuan

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
set<vector<int>> vis;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
    vector<int> v1(9, 0), v2(9, 0);
    int num;
    while (cin >> num) {
        v1[0] = num;
        for (int i = 1; i < 9; i++) {
            cin >> v1[i];
        }
        for (int i = 0; i < 9; i++) {
            cin >> v2[i];
        }
        vis.clear();
        queue<vector<int>> Q;
        Q.push(v1);
        queue<int> D;
        D.push(0);
        bool ok = false;
        int dist = 0;
        while (!Q.empty()) {
            vector<int> state = Q.front();
            Q.pop();
            dist = D.front();
            D.pop();
            if (state == v2) {
                ok = true;
                break;
            }
            int z = find(state.begin(), state.end(), 0) - state.begin();
            int x = z / 3;
            int y = z % 3;
            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                int newz = newx * 3 + newy;
                if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
                    vector<int> vnew = state;
                    vnew[newz] = state[z];
                    vnew[z] = state[newz];
                    if (vis.find(vnew) == vis.end()) {
                        vis.insert(vnew);
                        Q.push(vnew);
                        D.push(dist + 1);
                    }
                }
            }
        }
        if (ok) {
            cout << dist << endl;
        }
        else cout << "impossible" << endl;
    }
    return 0;
}