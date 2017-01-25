//#include <cstring>
//#include <vector>
//#include <queue>
//using namespace std;
//
//const char* dirs = "NESW";
//const char* turns = "FLR";
//int dir_id(char c) { return strchr(dirs, c) - dirs; }
//int turn_id(char c) { return strchr(turns, c) - turns; }
//const int dr[] = { -1, 0, 1, 0 };
//const int dc[] = { 0, 1, 0, -1 };
//int r0, c0, dir;
//int r1, c1;
//int r2, c2;
//int has_edge[10][10][5][5];
//int d[10][10][5];
//
//struct Node {
//	int dir;
//	int r, c;
//	Node(int r, int c, int dir) :r(r), c(c), dir(dir) {}
//};
//
//Node walk(const Node& u, int turn) {
//	int dir = u.dir;
//	if (turn == 1) dir = (dir + 3) % 4;
//	if (turn == 2) dir = (dir + 1) % 4;
//	return Node(u.r + dr[dir], u.c + dc[dir], dir);
//}
//
//void print_ans(Node u) {
//	vector<Node> nodes;
//	for (;;) {
//		nodes.push_back(u);
//		if (d[u.r][u.c][u.dir] == 0) break;
//		u = p[u.r][u.c][u.dir];
//	}
//	nodes.push_back(Node(r0, c0, dir));
//
//	int cnt = 0;
//	for (int i = nodes.size() - 1; i >= 0; i--) {
//		if (cnt % 10 == 0) printf(" ");
//		printf(" (%d,%d)", nodes[i].r, nodes[i].c);
//		if (++cnt % 10 == 0) printf("\n");
//	}
//	if (nodes.size() % 10 != 0) printf("\n");
//}
//void solve() {
//	queue<Node> q;
//	memset(d, -1, sizeof(d));
//	Node u(r1, c1, dir);
//	d[u.r][u.c][u.dir] = 0;
//	q.push(u);
//	while (!q.empty()) {
//		Node u = q.front(); q.pop();
//		if (u.r == r2 && u.c == c2) {
//			print_ans(u);
//			return;
//		}
//		for (int i = 0; i < 3; i++) {
//			Node v = walk(u, i);
//			if (has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {
//				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
//				p[v.r][v.c][v.dir] = u;
//				q.push(v);
//			}
//		}
//	}
//	printf("No Solution Possible\n");
//}
//


// 2017-01-24-chenkuan

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
using namespace std;
string dirs_s("NESW");
string turns_s("FLR");
map<char, int> dirs({ {'N',0},{'E',1},{'S',2},{'W',3} });   // 4种方向
map<char, int> turns({ {'F', 0}, {'L', 1}, {'R', 2} });     // 3种转向
const vector<int> dr{ -1, 0, 1, 0 };
const vector<int> dc{ 0, 1, 0, -1 };
struct Node {
    int r, c, dir;
    Node(int r = 0, int c = 0, int dir = 0) :r(r), c(c), dir(dir) {}
};
vector<vector<bool>> grid;  // 坐标处是否有点
vector<vector<vector<vector<bool>>>> edge;  // 坐标处面向某方向往某方向转是否有路
vector<vector<vector<int>>> dest;   // 从起点到此状态的最短路径长度
vector<vector<vector<Node>>> parent;    // 表示此状态的父结点
int r0, c0, dir0, r1, c1, r2, c2;

Node walk(const Node& node, int turn) {
    int dir = node.dir; // turn为0时表示不转向
    if (turn == 1) dir = (dir + 3) % 4;     // turn为1时表示逆时针转1(左转)，相当于顺时针转3
    else if (turn == 2) dir = (dir + 1) % 4;    // turn为2时表示顺时针转1(右转)
    return Node(node.r + dr[dir], node.c + dc[dir], dir);
}

bool inside(int r, int c) {
    if (r < 0 || r >= 10 || c < 0 || c >= 10) return false;
    return grid[r][c];
}

void printAns(Node node) {
    stack<Node> nodes;
    while (true) {
        nodes.push(node);
        if (dest[node.r][node.c][node.dir] == 0) break;
        node = parent[node.r][node.c][node.dir];
    }
    nodes.push(Node(r0, c0, dir0));
    int cnt = 0;
    while (!nodes.empty()) {
        Node node = nodes.top(); nodes.pop();
        if (cnt % 10 == 0) cout << " ";
        cout << " (" << node.r << "," << node.c << ")";
        if (++cnt % 10 == 0) cout << endl;
    }
    if (cnt % 10 != 0) cout << endl;
}

int main() {
    //freopen("eg6-14(816).in", "r", stdin);
    string name;
    while (cin >> name && name != "END") {
        cout << name << endl;
        grid.assign(10, vector<bool>(10, false));
        edge.assign(10, vector<vector<vector<bool>>>(10, vector<vector<bool>>(4, vector<bool>(3, false)))); // 4种方向，3种转向
        dest.assign(10, vector<vector<int>>(10, vector<int>(4, -1)));
        parent.assign(10, vector<vector<Node>>(10, vector<Node>(4, Node())));
        string dir_s;
        cin >> r0 >> c0 >> dir_s >> r2 >> c2;
        dir0 = dirs[dir_s[0]];
        r1 = r0 + dr[dir0];
        c1 = c0 + dc[dir0];
        grid[r0][c0] = grid[r2][c2] = true;

        int r, c;
        while (cin >> r && r > 0) {
            cin >> c;
            grid[r][c] = true;
            while (cin >> dir_s && dir_s != "*") {
                int dir = dirs[dir_s[0]];
                for (int i = 1; i < dir_s.size(); i++) {
                    edge[r][c][dir][turns[dir_s[i]]] = true;
                    //cout << "(" << r << "," << c << "," << dirs_s[dir] << ") can turn " << dir_s[i] << endl;
                }
            }
        }
        //cout << "grid:" << endl;
        //for (auto line : grid) {
        //    for (auto b : line) {
        //        if (b) cout << '1';
        //        else cout << '0';
        //    }
        //    cout << endl;
        //}
        queue<Node> Q;
        Node root(r1, c1, dir0);
        dest[r1][c1][dir0] = 0;
        Q.push(root);
        bool has_ans = false;
        while (!Q.empty()) {
            Node node = Q.front();  Q.pop();
            //cout << "(" << node.r << "," << node.c << "," << dirs_s[node.dir] << ")" << endl;
            if (node.r == r2 && node.c == c2) {
                has_ans = true;
                printAns(node);
                break;
            }
            for (int i = 0; i < 3; i++) {
                Node node_next = walk(node, i);
                //cout << "    -->(" << node_next.r << "," << node_next.c << "," << dirs_s[node_next.dir] << ")";
                if (inside(node_next.r, node_next.c) &&
                    edge[node.r][node.c][node.dir][i] &&
                    dest[node_next.r][node_next.c][node_next.dir] < 0) {
                    dest[node_next.r][node_next.c][node_next.dir] = dest[node.r][node.c][node.dir] + 1;
                    parent[node_next.r][node_next.c][node_next.dir] = node;
                    Q.push(node_next);
                    //cout << " selected";
                }
                //else if (!inside(node_next.r, node_next.c)) {
                //    cout << " not inside";
                //}
                //else if (!edge[node.r][node.c][node.dir][i]) {
                //    cout << " no edge";
                //}
                //else if (dest[node_next.r][node_next.c][node_next.dir] >= 0) {
                //    cout << " dest >= 0";
                //}
                //cout << endl;
            }
        }
        if (!has_ans) {
            cout << "  No Solution Possible" << endl;
        }
    }
    return 0;
}


// 2017-01-25-chenkuan

//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <set>
//#include <queue>
//#include <stack>
//using namespace std;
//map<char, int> dir_id{ {'N', 0}, {'E', 1}, {'S', 2}, {'W', 3} };
//map<char, int> turn_id{ {'L', -1}, {'F', 0}, {'R', 1} };
//map<char, int> dr{ {'N', -1}, {'E', 0}, {'S', 1}, {'W', 0} };
//map<char, int> dc{ {'N', 0}, {'E', 1}, {'S', 0}, {'W', -1} };
//const string dirs = "NESW";
//struct Point {
//    int r, c;
//    Point(int r = 0, int c = 0) :r(r), c(c) {}
//    bool operator < (const Point& p) const {
//        return r < p.r || (r == p.r && c < p.c);
//    }
//};
//set<Point> points;
//struct Node {
//    Point point;
//    char dir;
//    map<char, int> dir_dest;
//    map<char, set<char>> dir_turns;
//    Point parent;
//    Node(Point p = Point(), char dir = 'N', Point parent = Point()) :point(p), dir(dir), parent(parent) {
//        dir_dest = { {'N', -1}, {'E', -1}, {'S', -1}, {'W', -1} };
//        dir_turns.clear();
//    }
//};
//map<Point, Node> point_node;
//
//Point walk(Point p, char& dir, char turn) {
//    int dir_int = dir_id[dir];
//    int turn_int = turn_id[turn];
//    char new_dir = dirs[(dir_int + turn_int + 4) % 4];
//    dir = new_dir;
//    Point point(p.r, p.c);
//    point.r += dr[dir];
//    point.c += dc[dir];
//    return point;
//}
//
//int main() {
//    freopen("eg6-14(816).in", "r", stdin);
//    string name;
//    while (cin >> name && name != "END") {
//        cout << name << endl;
//
//        points.clear();
//        point_node.clear();
//
//        Point p_start, p_end;
//        string dir_s;
//        cin >> p_start.r >> p_start.c >> dir_s >> p_end.r >> p_end.c;
//        points.insert(p_start);
//        points.insert(p_end);
//
//        Point p_first;
//        p_first.r = p_start.r + dr[dir_s[0]];
//        p_first.c = p_start.c + dc[dir_s[0]];
// 
//        int r, c;
//        string dir_turn_s;
//        while (cin >> r && r != 0) {
//            cin >> c;
//            Point point(r, c);
//            points.insert(point);
//            Node node(point);
//            while (cin >> dir_turn_s && dir_turn_s != "*") {
//                char dir = dir_turn_s[0];
//                node.dir_turns[dir] = set<char>();
//                for (int i = 1; i < dir_turn_s.size(); i++) {
//                    node.dir_turns[dir].insert(dir_turn_s[i]);
//                }
//            }
//            point_node[point] = node;
//        }
//
//        //cout << "there are " << points.size() << " points" << endl;
//        //for (auto p : points) {
//        //    cout << "(" << p.r << "," << p.c << ") ";
//        //}
//        //cout << endl;
//
//        point_node[p_first].dir = dir_s[0];
//
//        queue<Point> Q;
//        Q.push(p_first);
//        bool has_ans = false;
//        while (!Q.empty()) {
//            Point point = Q.front(); Q.pop();
//            //cout << "(" << point.r << "," << point.c << ")-->" << endl;
//            if (point.r == p_end.r && point.c == p_end.c) {
//                has_ans = true;
//                break;
//            }
//            Node node = point_node[point];
//            char dir = node.dir;
//            set<char> turns = node.dir_turns[dir];
//            //cout << "(" << point.r << "," << point.c << "):::Node(" << dir << "," << ")" << endl;
//            for (auto turn : turns) {
//                Point point_new = walk(point, dir, turn);
//                if (points.find(point_new) == points.end()) {
//                    cout << "new point (" << point_new.r << "," << point_new.c << ") cannot find" << endl;
//                    continue;
//                }
//                if (point_node[point_new].dir_dest[dir] >= 0) {
//                    cout << "new point (" << point_new.r << "," << point_new.c << ") dest >= 0" << endl;
//                    continue;
//                }
//                point_node[point_new].dir = dir;
//                point_node[point_new].dir_dest[dir] = node.dir_dest[node.dir] + 1;
//                point_node[point_new].parent = point;
//                cout << "(" << point_new.r << "," << point_new.c << ")::parent::(" << point.r << "," << point.c << ")" << endl;
//                Q.push(point_new);
//            }
//        }
//        cout << endl;
//
//        point_node[p_first].parent = p_start;
//
//        if (has_ans) {
//            stack<Point> pointS;
//            Point p_zero;
//            Point p = p_end;
//            while (p.r != 0 && p.c != 0) {
//                pointS.push(p);
//                p = point_node[p].parent;
//            }
//            int cnt = 0;
//            while (!pointS.empty()) {
//                if (cnt % 10 == 0) cout << ' ';
//                p = pointS.top(); pointS.pop();
//                cout << " (" << p.r << "," << p.c << ")";
//                if (++cnt % 10 == 0) cout << endl;
//            }
//            if (cnt% 10 != 0) cout << endl;
//        }
//        else {
//            cout << "  No Solution Possible" << endl;
//        }
//        cout << "print ans end" << endl;
//    }
//    return 0;
//}
