#include <iostream>
#include <iomanip>
using namespace std;
class CTime;
class CDate {
	friend void Display(CDate& date, CTime& time);
private:
	int year, month, day;
public:
	CDate(int y, int m, int d):year(y),month(m),day(d) {}
};

class CTime {
	friend void Display(CDate& date, CTime& time);
private:
	int hour, min, s;
public:
	CTime(int h, int m, int s):hour(h),min(m),s(s) {}
};

void Display(CDate& date, CTime& time) {
	cout << date.year <<"-"<< setfill('0') << setw(2) << date.month<<"-"<<setfill('0')<<setw(2)<<date.day<<" ";
	cout << setfill('0') << setw(2) << time.hour << ":" << setfill('0') << setw(2) << time.min << ":" << setfill('0') << setw(2) << time.s << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int y, m,d;
		int h, min, s;
		cin >> y >> m >> d >> h >> min >> s;
		CDate date(y, m, d);
		CTime time(h, min, s);
		Display(date, time);
	}
	return 0;
}