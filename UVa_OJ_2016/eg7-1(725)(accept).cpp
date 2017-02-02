//#include <cstdio>
//#include <cstring>
//
//int n;
//int buf[10];
//int all;
//
//bool noRepeat() {
//	int tmp[10] = { 0 };
//	for (int i = 0; i < 10; i++) {
//		if (tmp[buf[i]] > 0) return false;
//		tmp[buf[i]]++;
//	}
//	return true;
//}
//
//void search() {
//	for (int f = 0; f < 10; f++) {
//		for (int g = 0; g < 10; g++) {
//			for (int h = 0; h < 10; h++) {
//				for (int i = 0; i < 10; i++) {
//					for (int j = 0; j < 10; j++) {
//						int num = j + 10 * i + 100 * h + 1000 * g + 10000 * f;
//						int num2 = num * n;
//						if (num2 > 98765) return;
//						buf[0] = f;
//						buf[1] = g;
//						buf[2] = h;
//						buf[3] = i;
//						buf[4] = j;
//						int size = 5;
//						while (num2) {
//							buf[size++] = num2 % 10;
//							num2 /= 10;
//						}
//						if (noRepeat()) {
//							all++;
//							for (int i = 9; i >= 5; i--) {
//								printf("%d", buf[i]);
//							}
//							printf(" / %d%d%d%d%d = %d\n", f, g, h, i, j, n);
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	int cnt = 0;
//	while (scanf("%d", &n) != EOF && n != 0) {
//		if (cnt++ > 0) printf("\n");
//		memset(buf, 0, sizeof(buf));
//		all = 0;
//		search();
//		if (all == 0) {
//			printf("There are no solutions for %d.\n", n);
//		}
//	}
//}


// 2017-01-30-chenkuan

#include <iostream>
using namespace std;
int n;
int buf[10];
bool has_ans;

bool noRepeat() {
    int hash[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        hash[buf[i]]++;
    }
    for (int i = 0; i < 10; i++) {
        if (hash[i] != 1) return false;
    }
    return true;
}

void search() {
    for (buf[0] = 0; buf[0] < 10; buf[0]++) {
        for (buf[1] = 0; buf[1] < 10; buf[1]++) {
            for (buf[2] = 0; buf[2] < 10; buf[2]++) {
                for (buf[3] = 0; buf[3] < 10; buf[3]++) {
                    for (buf[4] = 0; buf[4] < 10; buf[4]++) {
                        int num = n * (buf[0] * 10000 + buf[1] * 1000 + buf[2] * 100 + buf[3] * 10 + buf[4]);
                        if (num > 98765) return;
                        for (int i = 0; i < 5; i++) {
                            buf[i + 5] = num % 10;
                            num /= 10;
                        }
                        if (noRepeat()) {
                            has_ans = true;
                            for (int i = 9; i >= 5; i--) {
                                cout << buf[i];
                            }
                            cout << " / ";
                            for (int i = 0; i < 5; i++) {
                                cout << buf[i];
                            }
                            cout << " = " << n << endl;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int kase = 0;
    while (cin >> n && n != 0) {
        if (kase++) cout << endl;
        has_ans = false;
        search();
        if (!has_ans) cout << "There are no solutions for " << n << "." << endl;
    }
}