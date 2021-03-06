﻿//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//const int maxn = 100 + 5;
//
//typedef struct building {
//	int id;
//	double x, y, w, d, h;
//	bool operator < (const Buidling& rhs) const {
//		return x < rhs.x || (x == rhs.x && y < rhs.y);
//	}
//} Buidling;
//
//struct building b[maxn];
//
//int n;
//double x[maxn * 2];
//
//bool cover(int i, double mx) {
//	return b[i].x <= mx && b[i].x + b[i].w >= mx;
//}
//
//bool visible(int i, double mx) {
//	if (!cover(i, mx)) return false;
//	for (int k = 0; k < n; k++) {
//		if (b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx)) return false;
//	}
//	return true;
//}
//
//int main() {
//	int kase = 0;
//	while (scanf("%d", &n) == 1 && n) {
//		for (int i = 0; i < n; i++) {
//			scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
//			x[i * 2] = b[i].x;
//			x[i * 2 + 1] = b[i].x + b[i].w;
//			b[i].id = i + 1;
//		}
//		sort(b, b + n);
//		sort(x, x + n * 2);
//		int m = unique(x, x + n * 2) - x;
//		if (kase++)	printf("\n");
//		printf("For map #%d, the visible buildings are numbered as follows:\n%d", kase, b[0].id);
//		for (int i = 1; i < n; i++) {
//			bool vis = false;
//			for (int j = 0; j < m - 1; j++) {
//				if (visible(i, (x[j] + x[j + 1]) / 2)) {
//					vis = true;
//					break;
//				}
//			}
//			if (vis)	printf(" %d", b[i].id);
//		}
//		printf("\n");
//	}
//	return 0;
//}


// 2017-01-18-chenkuan

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Building {
    int id;
    double x, y, w, d, h;
    bool operator < (const Building& b2) const {
        return x < b2.x || (x == b2.x && y < b2.y);
    }
};
vector<Building> buidlings;
vector<double> x_pos;   // 所有建筑的两端x坐标

// 判断坐标mx是否在建筑物i两端坐标中
bool cover(int i, double mx) {
    return buidlings[i].x <= mx && buidlings[i].x + buidlings[i].w >= mx;
}

// 判断建筑物i在x=mx处是否可见
bool visible(int i, double mx) {
    if (!cover(i, mx)) return false;
    for (int k = 0; k < buidlings.size(); k++) {
        if (cover(k, mx) && buidlings[k].y < buidlings[i].y
            && buidlings[k].h >= buidlings[i].h) {
            return false;
        }
    }
    return true;
}

int main() {
    int kase = 0, n;
    while (cin >> n && n != 0) {
        buidlings.clear();
        x_pos.clear();
        for (int i = 0; i < n; i++) {
            Building building;
            building.id = i + 1;
            cin >> building.x >> building.y >> building.w >> building.d >> building.h;
            buidlings.push_back(building);
            x_pos.push_back(building.x);
            x_pos.push_back(building.x + building.w);
        }
        sort(buidlings.begin(), buidlings.end());
        sort(x_pos.begin(), x_pos.end());
        x_pos.erase(unique(x_pos.begin(), x_pos.end()), x_pos.end());
        if (kase++) {
            cout << endl;
        }
        cout << "For map #" << kase << ", the visible buildings are numbered as follows:" << endl;
        cout << buidlings[0].id;
        for (int i = 1; i < n; i++) {
            bool vis = false;
            for (auto it = x_pos.begin(); it != x_pos.end() - 1; it++) {
                if (visible(i, (*it + *(it + 1)) / 2)) {
                    vis = true;
                    break;
                }
            }
            if (vis) {
                cout << " " << buidlings[i].id;
            }
        }
        cout << endl;
    }
    return 0;
}