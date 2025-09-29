#include<iostream>
using namespace std;
class Time {
	int hour, minute, second;
public:
	Time(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	Time& operator++() {
		second++;
		if (second >= 60) {
			second -= 60;
			minute++;
			if (minute >= 60) {
				minute -= 60;
				hour++;
				if (hour >= 12) {
					hour -= 12;
				}
			}
		}
		return *this;
	}
	Time operator--(int) {
		Time temp = *this;
		second--;
		if (second <0) {
			second += 60;
			minute--;
			if (minute < 0) {
				minute += 60;
				hour--;
				if (hour < 0) {
					hour += 12;
				}
			}
		}
		return temp;
	}
	void print() {
		cout << hour << ":" << minute << ":" << second << endl;
	}
};
int main() {
	int h, m, s;
	cin >> h >> m >> s;
	Time time1(h,m,s);
	int t,temp;
	cin >> t;
	while (t--) {
		cin >> temp;
		if (temp > 0) {
			for (int i = 0;i < temp;i++) {
				++time1;
			}
		}
		else {
			for (int i = 0;i < (-temp);i++) {
				time1--;
			}
		}
		time1.print();
	}
	return 0;
}