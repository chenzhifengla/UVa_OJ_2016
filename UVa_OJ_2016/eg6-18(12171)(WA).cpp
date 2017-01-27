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
//        //dfs(0, 0, 0);
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
using namespace std;
struct Box {
    int x0, y0, z0;
    int x, y, z;
};
vector<Box> boxes;
vector<int> croods[3];
vector<vector<vector<bool>>> G;
vector<vector<vector<bool>>> vis;
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
    freopen("eg6-18(12171).in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        boxes.clear();
        for (auto& crood : croods) {
            crood.clear();
            crood.push_back(0);
            crood.push_back(501);
        }
        for (int i = 0; i < n; i++) {
            Box box;
            cin >> box.x0 >> box.y0 >> box.z0 >> box.x >> box.y >> box.z;
            croods[0].push_back(box.x0);
            croods[0].push_back(box.x0 + box.x);
            croods[1].push_back(box.y0);
            croods[1].push_back(box.y0 + box.y);
            croods[2].push_back(box.z0);
            croods[2].push_back(box.z0 + box.z);
            boxes.push_back(box);
        }
        for (auto& crood : croods) {
            sort(crood.begin(), crood.end());
            crood.erase(unique(crood.begin(), crood.end()), crood.end());
        }
        G.assign(croods[0].size(), vector<vector<bool>>(croods[1].size(), vector<bool>(croods[2].size(), false)));
        vis = G;
        for (auto& box : boxes) {
            int ix = 0;
            while (croods[0][ix] < box.x0) ix++;
            for (; croods[0][ix] < box.x0 + box.x; ix++) {
                int iy = 0;
                while (croods[1][iy] < box.y0) iy++;
                for (; croods[1][iy] < box.y0 + box.y; iy++) {
                    int iz = 0;
                    while (croods[2][iz] < box.z0) iz++;
                    for (; croods[2][iz] < box.z0 + box.z; iz++) {
                        G[ix][iy][iz] = true;
                    }
                }
            }
        }
        int v_air = 0;
        stack<Point> S;
        v_air += (croods[0][1] - croods[0][0]) *
            (croods[1][1] - croods[1][0]) *
            (croods[2][1] - croods[2][0]);
        S.emplace(0, 0, 0);
        int x, y, z, x1, y1, z1;
        while (!S.empty()) {
            Point point = S.top();
            x = point.x; y = point.y; z = point.z;
            //vis[x][y][z] = true;
            //v_air += (croods[0][x + 1] - croods[0][x]) * 
            //    (croods[1][y + 1] - croods[1][y]) * 
            //    (croods[2][z + 1] - croods[2][z]);
            //cout << "(" << croods[0][x] << "," << croods[1][y] << "," << croods[2][z] << ") -- ("
            //        << croods[0][x + 1] << "," << croods[1][y + 1] << "," << croods[2][z + 1] << "), v=" << (croods[0][x + 1] - croods[0][x]) *
            //        (croods[1][y + 1] - croods[1][y]) *
            //        (croods[2][z + 1] - croods[2][z]) << endl;
            bool has_neibor = false;
            for (int i = 0; i < 6; i++) {
                x1 = x + step[i][0];
                y1 = y + step[i][1];
                z1 = z + step[i][2];
                if (x1 < 0 || x1 >= croods[0].size() - 1) continue;
                if (y1 < 0 || y1 >= croods[1].size() - 1) continue;
                if (z1 < 0 || z1 >= croods[2].size() - 1) continue;
                if (vis[x1][y1][z1] || G[x1][y1][z1]) continue;
                //if (x1 == 4 && y1 == 2 && z1 == 2) {
                //    cout << "422" << endl;
                //}
                vis[x1][y1][z1] = true;
                v_air += (croods[0][x1 + 1] - croods[0][x1]) * 
                    (croods[1][y1 + 1] - croods[1][y1]) * 
                    (croods[2][z1 + 1] - croods[2][z1]);
                //cout << "(" << croods[0][x1] << "," << croods[1][y1] << "," << croods[2][z1] << ") -- ("
                //        << croods[0][x1 + 1] << "," << croods[1][y1 + 1] << "," << croods[2][z1 + 1] << "), v=" << (croods[0][x1 + 1] - croods[0][x1]) *
                //        (croods[1][y1 + 1] - croods[1][y1]) *
                //        (croods[2][z1 + 1] - croods[2][z1]) << endl;
                S.emplace(x1, y1, z1);
                has_neibor = true;
            }
            if (!has_neibor) S.pop();
        }
        //cout << "502 * 502 * 502=" << 502 * 502 * 502 << endl;
        //cout << "v_ari = " << v_air << endl;
        cout << "v_s = " << 501 * 501 * 501 - v_air << endl;
        //cout << 10 * 10 * 10 - v_air << endl;
    }
    return 0;
}