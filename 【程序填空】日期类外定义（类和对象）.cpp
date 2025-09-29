//头文件和日期类声明
#include<iostream>
#include<iomanip>
using namespace std;
 
class TDate {
private:
    int year,month,day;
public:
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}
    void set(int y,int m,int d);
    void print();
    void addOneDay();
};

//----在以下区域完成部分成员函数的类外定义----
/********** Write your code here! **********/
void TDate::set(int y,int m,int d){
	year=y;
	month=m;
	day=d;
}
void TDate::print()
{
	cout << setfill('0') << setw(4) << year
         << setfill('0') << setw(2) << month
         << setfill('0') << setw(2) << day;
}
int dayLimit(int year,int month){
	static int days[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month==2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))){
		return 29;
	}
	return days[month];
}
void TDate::addOneDay(){
	day++;
	if (day > dayLimit(year, month)){
		day=1;
		month++;
		if(month>12){
			month=1;
			year++;
		}
	}
}

/*******************************************/
//主函数如下
int main()
{   int t, y,m,d;
    cin>>t;
    while(t--)
    {	TDate d1;
		cin>>y>>m>>d;
		d1.set(y, m, d);
        cout<<"Today-";
        d1.print();
        d1.addOneDay();
        cout<<" Tomorrow-";
        d1.print();
		cout<<endl;
    }
    return 0;
}

