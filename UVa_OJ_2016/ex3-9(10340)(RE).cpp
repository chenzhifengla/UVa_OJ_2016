#include <cstdio>
#include <cstring>

int main() {
	char sub[1010];
	char all[1010];
	while (scanf("%s", sub) != EOF) {
		scanf("%s", all);
		int len_sub = strlen(sub);
		int len_all = strlen(all);
		int index_all = 0;
		int is_sub = 1;		//default is sub
		for (int i = 0; i < len_sub; i++) {
			//try to find this char
			int find = 0;	//default is not find
			for (; index_all < len_all; index_all++) {
				if (all[index_all] == sub[i]) {
					find = 1;	//when find, jump
					index_all++;
					break;
				}
			}
			if (!find) {
				is_sub = 0;
				break;
			}
		}
		if (is_sub) {
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}