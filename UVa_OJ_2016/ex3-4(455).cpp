//
// Created by chenkuaan on 7/27/16.
//

#include <cstdio>
#include <cstring>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char s[100];
        scanf("%s", s);
		int len = strlen(s);
		int period = 0;
        for (int k = 1; k <= len; k++){		//k�Ƕγ�
			if (len % k != 0) continue;
			bool isPeriodString = true;
			for (int i = 1; i < len / k; i++)	//i�ǵڼ���
			{
				for (int j = 0; j < k; j++) {	//j�Ƕ����ַ����
					if (s[j] != s[j + k * i]) {
						isPeriodString = false;
						break;
					}
				}
				if (!isPeriodString) break;
			}
			if (isPeriodString) {
				printf("%d\n", k);
				if (t > 0) printf("\n");
				break;
			}
			else continue;
        }
    }
	return 0;
}