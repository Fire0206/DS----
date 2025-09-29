#include <iostream>  
using namespace std;
//下方完成题目要求的程序填空
/********** Write your code here! **********/
class CTime {
	int hour, minute, second;
public:
	CTime(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	CTime& operator++() {
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
	CTime operator++(int) {
		CTime temp = *this;
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
		return temp;
	}
	void print() {
		cout << hour << ":" << minute << ":" << second << endl;
	}
};


/*******************************************/
//主函数定义
int main()
{
	int h, m, s;
	cin >> h >> m >> s;
	CTime obj(h, m, s); //定义一个时钟类对象并初始化时分秒
	obj.print(); //输出开始时间

	obj++;
	obj.print();  //输出递增1秒的时间

	++obj;
	obj.print(); //输出再递增1秒的时间

	return 0;
}
