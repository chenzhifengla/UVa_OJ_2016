#include <cstdio>
#include <cstring>

int main() {
	char cavity[1010];
	char tooth[1010];
	while (scanf("%s%s", cavity, tooth) != EOF) {
		int len_cav = strlen(cavity);
		int len_too = strlen(tooth);
		int len_add = 0;
		int could = 1;
		for (int i = 0; i < len_cav; i++) {
			//check it
			could = 1;
			int cav_index = i;
			for (int j = 0; j < len_too; j++, cav_index++) {
				if (cav_index < len_cav) {
					if (cavity[cav_index] == '2' && tooth[j] == '2') {
						could = 0;
						break;
					}
				}
				else break;
			}
			if (could) {
				len_add = (i + len_too) > len_cav ? (i + len_too) : len_cav;
				break;
			}
		}
		if (could) {
			printf("%d\n", len_add);
		}
		else printf("%d\n", len_cav + len_too);
	}
	return 0;
}