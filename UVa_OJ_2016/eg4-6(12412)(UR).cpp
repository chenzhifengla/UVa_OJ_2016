#include <cstdio>

void print_menu() {
	printf("Welcome to Student Performance Management System(SPMS).\n\n");
	printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
}

void add() {
	printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
}

void DQ(int isq) {
	char s[maxl];
	while (1) {
		printf("Please enter SID or name. Enter 0 to finish.\n");
		scanf("%s", s);
		if (strcmp(s, "0") == 0) break;
		int r = 0;
		for (int i = 0; i < n; i++) {
			if (!removed[i]) {

			}
		}
	}
}

int main() {
	while (1) {
		int choice;
		print_menu();
		scanf("%d", &choice);
		switch (choice) {
		case 1: add(); break;
		case 2: DQ(0); break;
		case 3: DQ(1); break;
		case 4: printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n"); break;
		case 5: stat();
		}
	}
	return 0;
}