// 2017-02-02-chenkuan

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> stones;
struct Node {
    int weight;
    double llen, rlen;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        double r;
        int s;
        cin >> r >> s;
        stones.assign(s, 0);
        for (int i = 0; i < s; i++) {
            cin >> stones[i];
        }
    }
}