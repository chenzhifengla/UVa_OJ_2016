//#include <cstdio>
//#include <cstring>
//
//const int len = 32;
//const int maxn = 1024 + 10;
//char s[maxn];
//int buf[len][len], cnt;
//
//void draw(const char* s, int& p, int r, int c, int w) {
//	char ch = s[p++];
//	if (ch == 'p') {
//		draw(s, p, r, c + w / 2, w / 2);
//		draw(s, p, r, c, w / 2);
//		draw(s, p, r + w / 2, c, w / 2);
//		draw(s, p, r + w / 2, c + w / 2, w / 2);
//	}
//	else if (ch == 'f') {
//		for (int i = r; i < r + w; i++) {
//			for (int j = c; j < c + w; j++) {
//				if (buf[i][j] == 0) {
//					buf[i][j] = 1;
//					cnt++;
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		memset(buf, 0, sizeof(buf));
//		cnt = 0;
//		for (int i = 0; i < 2; i++) {
//			scanf("%s", s);
//			int p = 0;
//			draw(s, p, 0, 0, len);
//		}
//		printf("There are %d black pixels.\n", cnt);
//	}
//	return 0;
//}


// 2017-01-24-chenkuan

#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<bool>> image;  // 32x32的图，true表黑，false表示白
string s;
int cnt;

int readTree(int pos, int r, int c, int len) {
    char ch = s[pos++];
    if (ch == 'f') {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (!image[r + i][c + j]) {
                    image[r + i][c + j] = true;
                    cnt++;
                }
            }
        }
    }
    else if (ch == 'p') {
        pos = readTree(pos, r,           c + len / 2,   len / 2);
        pos = readTree(pos, r,           c,             len / 2);
        pos = readTree(pos, r + len / 2, c,             len / 2);
        pos = readTree(pos, r + len / 2, c + len / 2,   len / 2);
    }
    return pos;
}

int main() {
    //freopen("eg6-11(297).in", "r", stdin);
    int n;
    cin >> n;
    while (n--) {
        image.assign(32, vector<bool>(32, false));
        cnt = 0;
        cin >> s;
        readTree(0, 0, 0, 32);
        cin >> s;
        readTree(0, 0, 0, 32);
        cout << "There are " << cnt << " black pixels." << endl;
    }
    return 0;
}