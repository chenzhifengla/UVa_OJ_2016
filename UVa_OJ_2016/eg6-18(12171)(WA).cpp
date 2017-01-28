//#include <cstdio>
//#include <string.h>
//
//const int maxn = 500 + 10;
//
//int buf[maxn][maxn][maxn];
//int flag[maxn][maxn][maxn];
//int n;
//int x0, y0, z0, x, y, z;
//int minx, miny, minz, maxx, maxy, maxz;
//int off[6][3] = {
//	1, 0, 0,
//	-1, 0, 0,
//	0, 1, 0,
//	0, -1, 0,
//	0, 0, 1,
//	0, 0, -1,
//};
//
//bool isInner(int x, int y, int z) {
//	if (x < minx || x > maxx || y < miny || y > maxy || z < minz || z > maxz)
//		return false;
//	flag[x][y][z] = 1;
//	for (int i = 0; i < 6; i++) {
//		int x1 = x + off[i][0];
//		int y1 = y + off[i][1];
//		int z1 = z + off[i][2];
//		if (buf[x1][y1][z1] == 0 && flag[x1][y1][z1] == 0 && !isInner(x1, y1, z1)) return false;
//	}
//	return true;
//}
//
//void fill(int x, int y, int z) {
//	flag[x][y][z] = 0;
//	for (int i = 0; i < 6; i++) {
//		int x1 = x + off[i][0];
//		int y1 = y + off[i][1];
//		int z1 = z + off[i][2];
//		if (buf[x1][y1][z1] == 0 && flag[x1][y1][z1] == 1) {
//			fill(x1, y1, z1);
//		}
//	}
//}
//
//
//int main() {
//	int t;
//	scanf("%d", &t);
//	while (t--) {
//		memset(buf, 0, sizeof(buf));
//		memset(flag, 0, sizeof(flag));
//		minx = miny = minz = maxn - 1;
//		maxx = maxy = maxz = 1;
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++) {
//			scanf("%d%d%d%d%d%d", &x0, &y0, &z0, &x, &y, &z);
//			minx = x0 < minx ? x0 : minx;
//			miny = y0 < miny ? y0 : miny;
//			minz = z0 < minz ? z0 : minz;
//			maxx = (x0 + x) > maxx ? (x0 + x) : maxx;
//			maxy = (y0 + y) > maxy ? (y0 + y) : maxy;
//			maxz = (z0 + z) > maxz ? (z0 + z) : maxz;
//			for (int j = 0; j < x; j++) {
//				for (int k = 0; k < y; k++) {
//					for (int m = 0; m < z; m++) {
//						buf[x0 + j][y0 + k][z0 + m] = 1;
//					}
//				}
//			}
//		}
//		for (int i = minx; i <= maxx; i++) {
//			for (int j = miny; j <= maxy; j++) {
//				for (int k = minz; k <= maxz; k++) {
//					if (buf[i][j][k] == 0 && flag[i][j][k] == 0) {
//						if (isInner(i, j, k)) {
//							fill(i, j, k);
//						}
//					}
//				}
//			}
//		}
//		int v = 0, surface = 0;
//		for (int i = minx; i <= maxx; i++) {
//			for (int j = miny; j <= maxy; j++) {
//				for (int k = minz; k <= maxz; k++) {
//					if (buf[i][j][k] == 1) {
//						v++;
//						for (int m = 0; m < 6; m++) {
//							if (buf[i + off[m][0]][j + off[m][1]][k + off[m][2]] == 0) {
//								surface++;
//							}
//						}
//					}
//				}
//			}
//		}
//		printf("%d %d\n", v, surface);
//	}
//	return 0;
//}


// 2017-01-26-chenkuan
// 采用map记录图的方式会超时，采用递归dfs的方式会栈溢出

//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//struct Box {
//    int x0, y0, z0;
//    int x, y, z;
//};
//vector<Box> boxes;
//vector<int> croods[3];
//map<int, map<int, map<int, bool>>> G;
//map<int, map<int, map<int, bool>>> vis;
//const int step[6][3] = {
//    -1, 0, 0,
//    1, 0, 0,
//    0, -1, 0,
//    0, 1, 0,
//    0, 0, -1,
//    0, 0, 1,
//};
//
//int v_air;
//
//void dfs(int x, int y, int z) { //x,y,z都是crood下面的下标，由crood决定增长值
//    //if (croods[0][x] == 1 && croods[1][y] == 2 && croods[2][z] == 3) {
//    //    cout << "123" << endl;
//    //}
//    int xr = croods[0][x];
//    int yr = croods[1][y];
//    int zr = croods[2][z];  // 这些表示实际坐标
//    vis[xr][yr][zr] = true;
//    v_air += (croods[0][x + 1] - xr) * (croods[1][y + 1] - yr) * (croods[2][z + 1] - zr);
//    cout << "(" << croods[0][x] << "," << croods[1][y] << "," << croods[2][z] << ") -- ("
//        << croods[0][x + 1] << "," << croods[1][y + 1] << "," << croods[2][z + 1] << "), v=" << (croods[0][x + 1] - croods[0][x]) *
//        (croods[1][y + 1] - croods[1][y]) *
//        (croods[2][z + 1] - croods[2][z]) << endl;
//    for (int i = 0; i < 6; i++) {
//        int x1 = x + step[i][0];
//        int y1 = y + step[i][1];
//        int z1 = z + step[i][2];    // 获得新点在crood下面的下标
//        if (x1 < 0 || x1 >= croods[0].size() - 1) continue;
//        if (y1 < 0 || y1 >= croods[1].size() - 1) continue;
//        if (z1 < 0 || z1 >= croods[2].size() - 1) continue;
//        xr = croods[0][x1];
//        yr = croods[1][y1];
//        zr = croods[2][z1]; // 获得新点的实际坐标
//        if (vis[xr][yr][zr] || G[xr][yr][zr]) continue;
//        //if (vis[croods[0][x1]][croods[1][y1]][croods[2][z1]]) continue;
//        //if (G[croods[0][x1]][croods[1][y1]][croods[2][z1]]) continue;
//        dfs(x1, y1, z1);
//    }
//}
//
//int main() {
//    freopen("eg6-18(12171).in", "r", stdin);
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        boxes.clear();
//        for (auto& crood : croods) {
//            crood.clear();
//            crood.push_back(0);
//            crood.push_back(501);
//        }
//        for (int i = 0; i < n; i++) {
//            Box box;
//            cin >> box.x0 >> box.y0 >> box.z0 >> box.x >> box.y >> box.z;
//            croods[0].push_back(box.x0);
//            croods[0].push_back(box.x0 + box.x);
//            croods[1].push_back(box.y0);
//            croods[1].push_back(box.y0 + box.y);
//            croods[2].push_back(box.z0);
//            croods[2].push_back(box.z0 + box.z);
//            boxes.push_back(box);
//        }
//        for (auto& crood : croods) {
//            sort(crood.begin(), crood.end());
//            crood.erase(unique(crood.begin(), crood.end()), crood.end());
//        }
//        G.clear();
//        vis.clear();
//        for (auto x : croods[0]) {
//            G[x] = map<int, map<int, bool>>();
//            for (auto y : croods[1]) {
//                G[x][y] = map<int, bool>();
//                for (auto z : croods[2]) {
//                    G[x][y][z] = false;
//                }
//            }
//        }
//        vis = G;
//        for (auto& box : boxes) {
//            for (auto itx = G.lower_bound(box.x0); itx != G.lower_bound(box.x0 + box.x); itx++) {
//                for (auto ity = itx->second.lower_bound(box.y0); ity != itx->second.lower_bound(box.y0 + box.y); ity++) {
//                    for (auto itz = ity->second.lower_bound(box.z0); itz != ity->second.lower_bound(box.z0 + box.z); itz++) {
//                        itz->second = true;
//                    }
//                }
//            }
//        }
//        v_air = 0;
//        dfs(0, 0, 0);
//        //cout << "502 * 502 * 502=" << 502 * 502 * 502 << endl;
//        //cout << v_air << endl;
//        cout << 501 * 501 * 501 - v_air << endl;
//        //cout << 10 * 10 * 10 - v_air << endl;
//    }
//    return 0;
//}


// 2017-01-27-chenkuan

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;
struct Box {
    int x0, y0, z0;
    int x1, y1, z1;
    Box(int x0, int y0, int z0, int x1, int y1, int z1) :x0(x0), y0(y0), z0(z0), x1(x1), y1(y1), z1(z1) {}
};
vector<Box> boxes;
vector<int> X, Y, Z;
int x_num, y_num, z_num;
const int maxn = 105;
const int maxnum = 1010;
bool G[maxn][maxn][maxn], vis[maxn][maxn][maxn];
const int step[6][3] = {
    -1, 0, 0,
    1, 0, 0,
    0, -1, 0,
    0, 1, 0,
    0, 0, -1,
    0, 0, 1,
};

struct Point {
    int x, y, z;
    Point(int x, int y, int z):x(x),y(y),z(z){}
};

int main() {
#ifdef LOCAL
    freopen("eg6-18(12171).in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        boxes.clear();
        X.assign({ 0, maxnum });
        Y.assign({ 0, maxnum });
        Z.assign({ 0, maxnum });
        int x0, y0, z0, x, y, z, x1, y1, z1;
        for (int i = 0; i < n; i++) {
            cin >> x0 >> y0 >> z0 >> x >> y >> z;
            X.push_back(x0);    X.push_back(x0 + x);
            Y.push_back(y0);    Y.push_back(y0 + y);
            Z.push_back(z0);    Z.push_back(z0 + z);
            boxes.emplace_back(x0, y0, z0, x0 + x, y0 + y, z0 + z);
        }
        sort(X.begin(), X.end());
        x_num = unique(X.begin(), X.end()) - X.begin();
        sort(Y.begin(), Y.end());
        y_num = unique(Y.begin(), Y.end()) - Y.begin();
        sort(Z.begin(), Z.end());
        z_num = unique(Z.begin(), Z.end()) - Z.begin();
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        int ix, iy, iz;
        for (auto& box : boxes) {
            for (ix = 0; X[ix] < box.x0; ix++);
            for (; X[ix] < box.x1; ix++) {
                for (iy = 0; Y[iy] < box.y0; iy++);
                for (; Y[iy] < box.y1; iy++) {
                    for (iz = 0; Z[iz] < box.z0; iz++);
                    for (; Z[iz] < box.z1; iz++) {
                        G[ix][iy][iz] = true;
                    }
                }

            }
        }
        int v_air = 0, s_air = 0;
        stack<Point> S;
        S.emplace(0, 0, 0);
        while (!S.empty()) {
            Point point = S.top();
            S.pop();
            x = point.x; y = point.y; z = point.z;
            if (!vis[x][y][z]) {
                vis[x][y][z] = true;
                v_air += (X[x + 1] - X[x]) * (Y[y + 1] - Y[y]) * (Z[z + 1] - Z[z]);
                for (int i = 0; i < 6; i++) {
                    x1 = x + step[i][0];
                    y1 = y + step[i][1];
                    z1 = z + step[i][2];
                    if (x1 < 0 || x1 >= x_num - 1 || y1 < 0 || y1 >= y_num - 1 || z1 < 0 || z1 >= z_num - 1) continue;
                    if (vis[x1][y1][z1]) continue;
                    if (G[x1][y1][z1]) {
                        if (i == 0 || i == 1) {
                            s_air += (Y[y1 + 1] - Y[y1]) * (Z[z1 + 1] - Z[z1]);
                        }
                        else if (i == 2 || i == 3) {
                            s_air += (X[x1 + 1] - X[x1]) * (Z[z1 + 1] - Z[z1]);
                        }
                        else {
                            s_air += (X[x1 + 1] - X[x1]) * (Y[y1 + 1] - Y[y1]);
                        }
                        continue;
                    }
                    S.emplace(x1, y1, z1);
                }
            }
        }
        cout << s_air << ' ' << maxnum * maxnum * maxnum - v_air << endl;
    }
    return 0;
}