#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
	char name[20];
	int opTime, reTime;
	int num, roomNum, beginTime, bedNum, beginTime2;
};

struct Room {
	int num;
	int poptime;
	int usedtime;
	Patient patient;
};

struct cmp {
	bool operator() (const Room a, const Room b) const {
		if (a.poptime != b.poptime) return a.poptime > b.poptime;
		else return a.num > b.num;
	}
};

struct cmp2 {
	bool operator() (const Patient a, const Patient b) const {
		return a.num > b.num;
	}
};

struct Time {
	int hour, minute;
};

queue<Patient> patients;
queue<Room> noSurgeringRoom;	
priority_queue<Room, vector<Room>, cmp> surgeringRoom;	//根据弹出时间排序,其次是手术室编号
queue<Room> surgery2Recovery;
queue<Room> noRecoveringRoom;
priority_queue<Room, vector<Room>, cmp> recoveringRoom;
priority_queue<Patient, vector<Patient>, cmp2> recoveryPatients;

Time getTime(int m) {
	Time t;
	t.hour = m / 60;
	t.minute = m % 60;
	return t;
}

int main() {
	int n, m, T, t1, t2, t3, k;
	scanf("%d%d%d%d%d%d%d", &n, &m, &T, &t1, &t2, &t3, &k);
	for (int i = 0; i < k; i++) {
		Patient patient;
		patient.num = i + 1;
		scanf("%s%d%d", patient.name, &patient.opTime, &patient.reTime);
		patients.push(patient);
	}
	int starttime = T * 60;
	for (int i = 0; i < n; i++) {
		Room sr;
		sr.num = i;
		sr.poptime = starttime;
		sr.usedtime = 0;
		noSurgeringRoom.push(sr);
	}
	for (int i = 0; i < m; i++) {
		Room rr;
		rr.num = i;
		rr.poptime = starttime;
		rr.usedtime = 0;
		noRecoveringRoom.push(rr);
	}
	int time = starttime;
	for (; ; time++) {
		//按分钟模拟
		//如果所有队列都为空，则结束循环
		if (patients.empty() && surgeringRoom.empty() &&
			noSurgeringRoom.empty() && surgery2Recovery.empty() &&
			recoveringRoom.empty() && noRecoveringRoom.empty()) break;
		//读病人队列和空手术室队列进手术室
		while (!noSurgeringRoom.empty() && noSurgeringRoom.front().poptime == time && !patients.empty()) {
			Patient p = patients.front();
			patients.pop();

			Room sr = noSurgeringRoom.front();
			noSurgeringRoom.pop();
			p.roomNum = sr.num;
			p.beginTime = time;

			sr.patient = p;
			sr.poptime = p.opTime + time;
			sr.usedtime += p.opTime;
			surgeringRoom.push(sr);
		}
		//读正在手术的手术室队列出病人，进转移队列，并空出手术室
		while (!surgeringRoom.empty() && surgeringRoom.top().poptime == time) {
			Room sr = surgeringRoom.top();
			surgeringRoom.pop();
			Patient p = sr.patient;

			Room t;
			t.patient = p;
			t.poptime = time + t1;
			surgery2Recovery.push(t);
			
			sr.poptime = time + t2;
			noSurgeringRoom.push(sr);
		}
		//读转移队列和空恢复室队列进恢复室队列
		while (!surgery2Recovery.empty() && surgery2Recovery.front().poptime == time) {
			Patient p = surgery2Recovery.front().patient;
			surgery2Recovery.pop();

			Room rr = noRecoveringRoom.front();
			noRecoveringRoom.pop();
			p.bedNum = rr.num;
			p.beginTime2 = time;

			rr.patient = p;
			rr.poptime = time + p.reTime;
			rr.usedtime += p.reTime;
			recoveringRoom.push(rr);
		}
		//读恢复室队列空出恢复室
		while (!recoveringRoom.empty() && recoveringRoom.top().poptime == time) {
			Room rr = recoveringRoom.top();
			Patient p = rr.patient;
			recoveryPatients.push(p);
			recoveringRoom.pop();

			rr.poptime = time + t3;
			noRecoveringRoom.push(rr);
		}
	}
	if (k >= 10 && k < 100) printf(" "); else if (k == 100) printf("  ");
	printf("Patient          Operating Room          Recovery Room\n");
	if (k >= 10 && k < 100) printf(" "); else if (k == 100) printf("  ");
	printf("#  Name     Room#  Begin   End      Bed#  Begin    End\n");
	if (k >= 10 && k < 100) printf(" "); else if (k == 100) printf("  ");
	printf("------------------------------------------------------\n");
	while (!recoveryPatients.empty()) {
		Patient p = recoveryPatients.top();
		recoveryPatients.pop();
		if (k < 10) printf("%d", p.num);
		else if (k < 100) printf("%2d", p.num);
		else printf("%3d", p.num);
		printf("  ");
		printf("%-10s", p.name);
		printf("%2d", p.roomNum);
		printf("   ");
		Time opTime = getTime(p.beginTime);
		printf("%2d:%02d", opTime.hour, opTime.minute);
		printf("   ");
		Time opEndTime = getTime(p.beginTime + p.opTime);
		printf("%2d:%02d", opEndTime.hour, opEndTime.minute);
		printf("     ");
		printf("%2d", p.bedNum);
		printf("   ");
		Time reTime = getTime(p.beginTime2);
		printf("%2d:%02d", reTime.hour, reTime.minute);
		printf("   ");
		Time reEndTime = getTime(p.beginTime2 + p.reTime);
		printf("%2d:%02d\n", reEndTime.hour, reEndTime.minute);
	}
	printf("Facility Utilization\n");
	printf("Type  # Minutes  %% Used\n");
	printf("-------------------------\n");
	int endtime = time - 1;
	if (endtime < 0) endtime = 0;
	while (!noSurgeringRoom.empty()) {
		Room sr = noSurgeringRoom.front();
		noSurgeringRoom.pop();
		sr.poptime = 0;
		surgeringRoom.push(sr);
	}
	while (!surgeringRoom.empty()) {
		Room sr = surgeringRoom.top();
		surgeringRoom.pop();
		printf("Room %2d%8d%5.2f\n", sr.num, sr.usedtime, sr.usedtime * 100.0 / (endtime - starttime));
	}

	while (!noRecoveringRoom.empty()) {
		Room rr = noRecoveringRoom.front();
		noRecoveringRoom.pop();
		rr.poptime = 0;
		recoveringRoom.push(rr);
	}
	while (!recoveringRoom.empty()) {
		Room rr = recoveringRoom.top();
		recoveringRoom.pop();
		printf("Bed%4d%8d%5.2f\n", rr.num, rr.usedtime, rr.usedtime * 100.0 / (endtime - starttime));
	}
	return 0;
}