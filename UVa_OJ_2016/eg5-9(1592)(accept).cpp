// 2017-01-17-chenkuan

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int r, c;
vector<vector<string>> table;
map<pair<int, int>, int> M;
map<string, int> string_to_id;
set<string> all_string;

pair<bool, pair<pair<int, int>, pair<int, int>>> searchTable() {
    for (int c1 = 0; c1 < c; c1++) {
        for (int c2 = c1 + 1; c2 < c; c2++) {
            M.clear();
            for (int i = 0; i < r; i++) {
                auto pair = make_pair(string_to_id[table[i][c1]], string_to_id[table[i][c2]]);
                if (M.find(pair)
                    != M.end()) {
                    return{ true, {{M[pair] + 1, i + 1}, {c1 + 1, c2 + 1}} };
                }
                else {
                    M[pair] = i;
                }
            }
        }
    }
    return{ false, { {0, 0},{0, 0} } };
}

int main() {
    //freopen("eg5-9(1592).in", "r", stdin);
    while (cin >> r >> c) {
        table.clear();
        M.clear();
        string_to_id.clear();
        all_string.clear();
        string line;
        getline(cin, line);
        for (int i = 0; i < r; i++) {
            vector<string> v;
            getline(cin, line);
            auto beg = line.begin();
            auto end = beg;
            while (true) {
                end = find(beg, line.end(), ',');
                string s(beg, end);
                v.push_back(s);
                all_string.insert(s);
                if (string_to_id.find(s) == string_to_id.end()) string_to_id[s] = string_to_id.size();
                if (end == line.end()) break;
                beg = end + 1;
            }
            table.push_back(v);
        }
        auto ans = searchTable();
        if (ans.first) {
            cout << "NO" << endl;
            cout << ans.second.first.first << ' ' << ans.second.first.second << endl;
            cout << ans.second.second.first << ' ' << ans.second.second.second << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}