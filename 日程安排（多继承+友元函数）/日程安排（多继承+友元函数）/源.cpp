#include<iostream>
#include<iomanip>
using namespace std;

class Date {
protected:
	int year, month, day;
public:
	Date(int y, int m, int d) :year(y), month(m), day(d) {}
};

class Time {
protected:
	int hour, minute, second;
public:
	Time(int h, int m, int s) :hour(h), minute(m), second(s) {}
};

class Schedule :public Date, public Time {
	int ID;
public:
	Schedule(int id, int y, int m, int d, int h, int m2, int s) :
		Date(y, m, d), Time(h, m2, s), ID(id) {
	}
	friend bool before(const Schedule& s1, const Schedule& s2);
	void print() {
		cout << ID << ": " << year << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(2) << day << " ";
		cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << second << endl;
	}
};

bool before(const Schedule& s1, const Schedule& s2) {
	if (s1.year < s2.year) return true;
	if (s1.year > s2.year) return false;
	if (s1.month < s2.month) return true;
	if (s1.month > s2.month) return false;
	if (s1.day < s2.day) return true;
	if (s1.day > s2.day) return false;
	if (s1.hour < s2.hour) return true;
	if (s1.hour > s2.hour) return false;
	if (s1.minute < s2.minute) return true;
	if (s1.minute > s2.minute) return false;
	return s1.second < s2.second;
}

int main() {
	int ID, year, month, day, hour, minute, second;
	Schedule s2(0, 9999, 12, 31, 23, 59, 59);
	while (1) {
		cin >> ID;
		if (ID == 0) {
			break;
		}
		cin >> year >> month >> day >> hour >> minute >> second;
		Schedule s1(ID, year, month, day, hour, minute, second);
		if (before(s1, s2)) {
			s2 = s1;
		}
	}
	cout << "The urgent schedule is No.";
	s2.print();
	return 0;
}