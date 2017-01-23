//#include <cstdio>
//#include <stack>
//#include <iostream>
//#include <string>
//using namespace std;
//
//struct Matrix {
//	int a, b;
//	Matrix(int a = 0, int b = 0) :a(a), b(b) {}
//}m[26];
//
//stack<Matrix> s;
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		string name;
//		cin >> name;
//		int k = name[0] - 'A';
//		cin >> m[k].a >> m[k].b;
//	}
//	string expr;
//	while (cin >> expr) {
//		int len = expr.length();
//		bool error = false;
//		int ans = 0;
//		for (int i = 0; i < len; i++) {
//			if (isalpha(expr[i])) {
//				s.push(m[expr[i] - 'A']);
//			}
//			else if (expr[i] == ')') {
//				Matrix m2 = s.top();
//				s.pop();
//				Matrix m1 = s.top();
//				s.pop();
//				if (m1.b != m2.a) {
//					error = true;
//					break;
//				}
//				ans += m1.a * m1.b * m2.b;
//				s.push(Matrix(m1.a, m2.b));
//			}
//		}
//		if (error) {
//			printf("error\n");
//		}
//		else {
//			printf("%d\n", ans);
//		}
//	}
//	return 0;
//}


// 2017-01-20-chenkuan

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

struct Matrix {
    int a, b;
    Matrix(int a = 0, int b = 0) :a(a), b(b) {}
};

int main() {
    //freopen("eg6-3(442).in", "r", stdin);
    int n;
    cin >> n;
    vector<Matrix> matrixs(26);
    while (n--) {
        string name;
        cin >> name;
        int index = name[0] - 'A';
        cin >> matrixs[index].a >> matrixs[index].b;
    }
    string cmd;
    while (cin >> cmd) {
        int num = 0;
        stack<Matrix> S;
        for (auto c : cmd) {
            if (isalpha(c)) {
                S.push(matrixs[c - 'A']);
            }
            else if (c == ')') {
                Matrix m2 = S.top(); S.pop();
                Matrix m1 = S.top(); S.pop();
                if (m1.b != m2.a) {
                    num = -1;
                    break;
                }
                else {
                    num += m1.a * m1.b * m2.b;
                    S.emplace(m1.a, m2.b);
                }
            }
        }
        if (num < 0) {
            cout << "error" << endl;
        }
        else {
            cout << num << endl;
        }
    }
    return 0;
}