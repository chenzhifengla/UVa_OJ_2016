//#include <cstdio>
//
//void print_menu() {
//	printf("Welcome to Student Performance Management System(SPMS).\n\n");
//	printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
//}
//
//void add() {
//	printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
//}
//
//void DQ(int isq) {
//	char s[maxl];
//	while (1) {
//		printf("Please enter SID or name. Enter 0 to finish.\n");
//		scanf("%s", s);
//		if (strcmp(s, "0") == 0) break;
//		int r = 0;
//		for (int i = 0; i < n; i++) {
//			if (!removed[i]) {
//
//			}
//		}
//	}
//}
//
//int main() {
//	while (1) {
//		int choice;
//		print_menu();
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1: add(); break;
//		case 2: DQ(0); break;
//		case 3: DQ(1); break;
//		case 4: printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n"); break;
//		case 5: stat();
//		}
//	}
//	return 0;
//}


// 2017-01-16-chenkuan

#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct Student{
    char sid[12];
    int cid;
    char name[12];
    int score[4];
    int score_sum;
    double score_aver;
};
Student stu[110];
int stu_num;

void print_menu() {
    printf("Welcome to Student Performance Management System(SPMS).\n\n");
    printf("1 - Add\n");
    printf("2 - Remove\n");
    printf("3 - Query\n");
    printf("4 - Show ranking\n");
    printf("5 - Show Statistics\n");
    printf("0 - Exit\n");
}

void add() {
    while (1) {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s", stu[stu_num].sid);
        if (strcmp(stu[stu_num].sid, "0") == 0) return;
        scanf("%d%s", &stu[stu_num].cid, stu[stu_num].name);
        for (int i = 0; i < 4; i++) {
            scanf("%d", &stu[stu_num].score[i]);
        }
        int find = 0;
        for (int i = 0; i < stu_num; i++) {
            if (strcmp(stu[i].sid, stu[stu_num].sid) == 0) {
                find = 1;
                break;
            }
        }
        if (find) {
            printf("Duplicated SID.\n");
        }
        else {
            stu[stu_num].score_sum = 0;
            for (int i = 0; i < 4; i++) {
                stu[stu_num].score_sum += stu[stu_num].score[i];
            }
            stu[stu_num].score_aver = (double)stu[stu_num].score_sum / 4;
            stu_num++;
        }
    }
}

void Remove() {
    while (1) {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        int new_stu_num = 0;
        char id_or_name[12];
        scanf("%s", id_or_name);
        if (strcmp(id_or_name, "0") == 0) return;
        if (isdigit(id_or_name[0])) {
            for (int i = 0; i < stu_num; i++) {
                if (strcmp(stu[i].sid, id_or_name) != 0) {
                    memcpy(&stu[new_stu_num++], &stu[i], sizeof(Student));
                }
            }
        }
        else {
            for (int i = 0; i < stu_num; i++) {
                if (strcmp(stu[i].name, id_or_name) != 0) {
                    memcpy(&stu[new_stu_num++], &stu[i], sizeof(Student));
                }
            }
        }
        printf("%d student(s) removed\n", stu_num - new_stu_num);
        stu_num = new_stu_num;
    }
}

int rank(int i) {
    int r = 1;
    for (int j = 0; j < stu_num; j++) {
        if (stu[j].score_sum > stu[i].score_sum) {
            r++;
        }
    }
    return r;
}

void print_query(int i) {
    printf("%d %s %d %s", rank(i), stu[i].sid, stu[i].cid, stu[i].name);
    for (int j = 0; j < 4; j++) {
        printf(" %d", stu[i].score[j]);
    }
    printf(" %d %.2f\n", stu[i].score_sum, stu[i].score_aver);
}

void query() {
    while (1) {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        char id_or_name[12];
        scanf("%s", id_or_name);
        if (strcmp(id_or_name, "0") == 0) return;
        if (isdigit(id_or_name[0])) {
            for (int i = 0; i < stu_num; i++) {
                if (strcmp(stu[i].sid, id_or_name) == 0) {
                    print_query(i);
                }
            }
        }
        else {
            for (int i = 0; i < stu_num; i++) {
                if (strcmp(stu[i].name, id_or_name) == 0) {
                    print_query(i);
                }
            }
        }
    }
}

double averScore(int cid, int subject_id) {
    int sum = 0, num = 0;
    for (int i = 0; i < stu_num; i++) {
        if (stu[i].cid == cid || cid == 0) {
            sum += stu[i].score[subject_id];
            num++;
        }
    }
    return (double)sum / num;
}

// 指定课程指定班级通过的人数，cid为0表示所有班级
void passedStd(int cid, int subject_id, int* passed, int* failed) {
    *passed = 0;
    *failed = 0;
    for (int i = 0; i < stu_num; i++) {
        if (stu[i].cid == cid || cid == 0) {
            if (stu[i].score[subject_id] >= 60) {
                (*passed)++;
            }
            else {
                (*failed)++;
            }
        }
    }
}

// 所有班级通过n项课程的人数
int passedAllStu(int cid, int n) {
    int num = 0;
    for (int i = 0; i < stu_num; i++) {
        if (stu[i].cid == cid || cid == 0) {
            int pass = 0;
            for (int j = 0; j < 4; j++) {
                if (stu[i].score[j] >= 60) {
                    pass++;
                }
            }
            if (n == 0) {
                if (pass == 0) num++;
            }
            else if (pass >= n) num++;
        }
    }
    return num;
}

void statistics() {
    printf("Please enter class ID, 0 for the whole statistics.\n");
    int cid;
    scanf("%d", &cid);
    char subject[4][20] = { "Chinese", "Mathematics", "English", "Programming" };
    int passed, failed;
    for (int i = 0; i < 4; i++) {
        printf("%s\n", subject[i]);
        printf("Average Score: %.2f\n", averScore(cid, i));
        passedStd(cid, i, &passed, &failed);
        printf("Number of passed students: %d\n", passed);
        printf("Number of failed students: %d\n\n", failed);
    }
    printf("Overall:\n");
    printf("Number of students who passed all subjects: %d\n", passedAllStu(cid, 4));
    printf("Number of students who passed 3 or more subjects: %d\n", passedAllStu(cid, 3));
    printf("Number of students who passed 2 or more subjects: %d\n", passedAllStu(cid, 2));
    printf("Number of students who passed 1 or more subjects: %d\n", passedAllStu(cid, 1));
    printf("Number of students who passed failed all subjects: %d\n\n", passedAllStu(cid, 0));
}

int main() {
    //freopen("eg4-6(12412).in", "r", stdin);
    stu_num = 0;
    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:add(); break;
        case 2:Remove(); break;
        case 3:query(); break;
        case 4:printf("Showing the ranklist hurts students' self-esteem. Don't do that."); break;
        case 5:statistics(); break;
        default:return 0;
        }
    }
    return 0;
}