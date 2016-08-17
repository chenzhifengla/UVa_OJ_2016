#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
	double x, y;
};

struct Map {
	string name;
	Point p1, p2;
	double area, height, width, h2wRatio;
	bool operator < (const Map& b) const {
		return this->area > b.area;
	}
};

struct Location {
	string name;
	Point p;
};

vector<Map> maps;
vector<Location> locations;
int level;
Location loca;

Location getLocation(string s) {
	for (int i = 0; i < locations.size(); i++) {
		if (locations[i].name == s) return locations[i];
	}
	Location l;
	l.name = "";
	return l;
}

bool inMap(Location l, Map map_) {
	if (l.p.x >= min(map_.p1.x, map_.p2.x) &&
		l.p.x <= max(map_.p1.x, map_.p2.x) &&
		l.p.y >= min(map_.p1.y, map_.p2.y) &&
		l.p.y <= max(map_.p1.y, map_.p2.y)) {
		return true;
	}
	else return false;
}

bool cmpDetail(Map a, Map b) {
	if (a.area != b.area) return a.area > b.area;
	double dista, distb;
	dista = pow(loca.p.x - (a.p1.x + a.p2.x) / 2, 2) +
		pow(loca.p.y - (a.p1.y + a.p2.y) / 2, 2);
	distb = pow(loca.p.x - (b.p1.x + b.p2.x) / 2, 2) +
		pow(loca.p.y - (b.p1.y + b.p2.y) / 2, 2);
	if (dista != distb) return dista < distb;
	if (a.h2wRatio != b.h2wRatio) return a.h2wRatio < b.h2wRatio;
	dista = pow(loca.p.x - max(a.p1.x, a.p2.x), 2) +
		pow(loca.p.y - min(a.p1.y, a.p2.y), 2);
	distb = pow(loca.p.x - max(b.p1.x, b.p2.x), 2) +
		pow(loca.p.y - min(b.p1.y, b.p2.y), 2);
	if (dista != distb) return dista < distb;
	return min(a.p1.x, a.p2.x) < min(b.p1.x, b.p2.x);
}

vector<Map> getMapContain(Location l) {
	vector<Map> map_;
	for (int i = 0; i < maps.size(); i++) {
		if (inMap(l, maps[i])) {
			map_.push_back(maps[i]);
		}
	}
	return map_;
}

int main() {
	string name;
	cin >> name;
	while (cin >> name && name != "LOCATIONS") {
		Map map_;
		map_.name = name;
		cin >> map_.p1.x >> map_.p1.y >> map_.p2.x >> map_.p2.y;
		map_.width = abs(map_.p1.x - map_.p2.x);
		map_.height = abs(map_.p1.y - map_.p2.y);
		map_.area = map_.width * map_.height;
		map_.h2wRatio = map_.height / map_.width;
		maps.push_back(map_);
	}
	sort(maps.begin(), maps.end());
	while (cin >> name && name != "REQUESTS") {
		Location location;
		location.name = name;
		cin >> location.p.x >> location.p.y;
		locations.push_back(location);
	}
	while (cin >> name && name != "END") {
		cin >> level;
		loca = getLocation(name);
		if (loca.name == "") {
			cout << name << " at detail level " << level << " unknown location" << endl;
		}
		else {
			vector<Map> containMaps = getMapContain(loca);
			if (containMaps.empty()) {
				cout << name << " at detail level " << level << " no map contains that location" << endl;
			}
			else {
				sort(containMaps.begin(), containMaps.end(), cmpDetail);
				if (containMaps.size() < level) {
					cout << name << " at detail level " << level;
					cout << " no map at that detail level; using ";
					cout << containMaps[containMaps.size() - 1].name << endl;
				}
				else {
					cout << name << " at detail level " << level;
					cout << " using " << containMaps[level - 1].name << endl;
				}
			}
		}
	}
	return 0;
}