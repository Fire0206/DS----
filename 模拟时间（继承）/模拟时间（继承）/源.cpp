#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class Time {
protected:
	int hour, minute, second;
public:
	Time(int h,int m,int s):hour(h),minute(m),second(s){}
};
class Time_12hours :public Time {
	char interval[5];
public:
	Time_12hours(int h, int m, int s,const char* inter) :Time(h, m, s) {
		strcpy_s(interval, inter);
	}
	void add() {
		second ++;
		if (second >= 60) {
			second = 0;
			minute++;
			if (minute >= 60) {
				minute = 0;
				hour++;
				if (hour >= 12) {
					hour = 0;
					if (strcmp(interval, "AM") == 0) {
						strcpy_s(interval, "PM");
					}
					else {
						strcpy_s(interval, "AM");
					}
				}
			}
		}
	}
	void del() {
		second--;
		if (second <0) {
			second = 59;
			minute--;
			if (minute < 0) {
				minute = 59;
				hour--;
				if (hour < 0) {
					hour = 11;
					if (strcmp(interval, "AM") == 0) {
						strcpy_s(interval, "PM");
					}
					else {
						strcpy_s(interval, "AM");
					}
				}
			}
		}
	}
	void operate(char op,int a) {
		for (int i = 0;i < a;i++) {
			if (op == '+') {
				add();
			}
			else {
				del();
			}
		}
	}
	void print() {
		cout << interval << " ";
		cout << setfill('0') << setw(2) << hour << ":";
		cout << setfill('0') << setw(2) << minute << ":";
		cout << setfill('0') << setw(2) << second << endl;
	}
};
int main() {
	int mode;
	while (1) {
		cin >> mode;
		const char* inter = "AM";
		if (mode == 0) {
			break;
		}
		int h, m, s ,a;
		char op;
		cin >> h >> m >> s >> op >> a;
		if (mode == 121) {
			inter = "AM";
		}
		else if (mode == 122) {
			inter = "PM";
		}
		Time_12hours t(h, m, s, inter);
		t.operate(op, a);
		t.print();
	}
	return 0;
}