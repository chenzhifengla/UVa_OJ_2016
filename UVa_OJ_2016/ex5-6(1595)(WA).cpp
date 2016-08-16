#include <iostream>
#include <algorithm>
using namespace std;


struct Point {
	int x, y;
};

Point points[1001];

bool cmp_greater(const Point a, const Point b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

bool cmp_less(const Point a, const Point b) {
	if (a.x == b.x) return a.y > b.y;
	else return a.x < b.x;
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &points[i].x, &points[i].y);
		}
		sort(points, points + n, cmp_greater);
		sort(points + n / 2, points + n, cmp_less);
		int sum = points[0].x + points[n - 1].x;
		bool isSymmetric = true;
		for (int i = 0; i < n / 2; i++) {
			if (points[i].x + points[n - 1 - i].x != sum || points[i].y != points[n - 1 - i].y) {
				isSymmetric = false;
				break;
			}
		}
		if (isSymmetric) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//struct PointList {
//	int x;
//	vector<int> ylist;
//	bool operator < (const PointList& b) const {
//		if (this->x != b.x) return this->x < b.x;
//		else return 0;
//	}
//};
//
//PointList points[1001];
//
//int main() {
//	int t;
//	scanf("%d", &t);
//	while (t--) {
//		int n;
//		scanf("%d", n);
//		for (int i = 0; i < n; i++) {
//			int x, y;
//			scanf("%d%d", &x, &y);
//			PointList p;
//			p.x = x;
//			p.ylist.push_back(y);
//		}
//	}
//}