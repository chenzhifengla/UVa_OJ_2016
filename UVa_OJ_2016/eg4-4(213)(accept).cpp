//#include <cstdio>
//#include <cstring>
//
//int readchar();
//int readint(int c);
//
//int code[8][1 << 8];	//code[len][value],len为编码长度，value是编码对应的十进制值
//int readcodes();
//
//int main() {
//	while (readcodes()) {
//		while (1) {
//			int len = readint(3);
//			if (len == 0) break;
//
//			while (1) {
//				int v = readint(len);
//
//				if (v == (1 << len) - 1) break;
//				putchar(code[len][v]);
//			}
//		}
//		putchar('\n');
//	}
//	return 0;
//}
//
//int readchar() {
//	while (1) {
//		int ch = getchar();
//		if (ch != '\n' && ch != '\r') return ch;
//	}
//}
//
//int readint(int c) {
//	int v = 0;
//	while (c--) {
//		v = v * 2 + readchar() - '0';
//	}
//	return v;
//}
//
//int readcodes() {
//	memset(code, 0, sizeof(code));
//	code[1][0] = readchar();
//	for (int len = 2; len <= 7; len++) {
//		for (int i = 0; i < (1 << len) - 1; i++) {
//			int ch = getchar();
//			if (ch == EOF) return 0;
//			if (ch == '\n' || ch == '\r') return 1;
//			code[len][i] = ch;
//		}
//	}
//	return 1;
//}


// 2017-01-15-chenkuan

#include <stdio.h>
#include <memory.h>
char code[8][1 << 8];   // 第一维表示编码长度，第二维表示编码的整数值，结果为对应的编码字符

char readchar() {
    while (1) {
        int c = getchar();
        if (c != '\n' && c != '\r') return c;
    }
}

int readCodeHead() {
    memset(code, 0, sizeof(code));
    code[1][0] = readchar();
    for (int len = 2; len <= 7; len++) {
        for (int i = 0; i < (1 << len) - 1; i++) {
            int c = getchar();
            if (c == EOF) return 0;
            if (c == '\n' || c == '\r') return 1;
            code[len][i] = c;
        }
    }
    return 1;
}

int readInt(int len) {
    int num = 0;
    while (len--) {
        num *= 2;
        num += readchar() - '0';
    }
    return num;
}

int main() {
    //freopen("eg4-4(213).in", "r", stdin);
    while (readCodeHead()) {
        while (1) {
            int len = readInt(3);   // 读取编码长度
            if (len == 0) {
                break;
            }
            while (1) {
                int num = readInt(len); // 读取编码长度的编码，返回整数值
                if (num == (1 << len) - 1) {  // 全为1退出
                    break;
                }
                putchar(code[len][num]);
            }
        }
        putchar('\n');
    }
    return 0;
}