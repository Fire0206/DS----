//头文件和类声明
#include <iostream>
using namespace std;

class MyDate {
private:
	int year;
	int month;
	int day;
public:
	MyDate(); //无参构造，默认日期2022-4-1，输出相关构造信息
	MyDate(int ty, int tm, int td); //有参构造，根据参数初始化，输出相关构造信息
	~MyDate(); 
	bool Before(MyDate &rd);
	void print()
	{ cout<<year<<"-"<<month<<"-"<<day; }
};
//下面填写类实现和主函数
/********** Write your code here! **********/
MyDate::MyDate()
{
	year=2022;
	month=4;
	day=1;
	cout<<"Date ";
	print();
	cout<<" default constructed"<<endl;
}
MyDate::MyDate(int ty, int tm, int td)
{
	year=ty;
	month=tm;
	day=td;
	cout<<"Date ";
	print();
	cout<<" constructed"<<endl;
}
MyDate::~MyDate()
{
	cout<<"Date ";
	print();
	cout<<" destructed"<<endl;
}
bool MyDate::Before(MyDate &rd)
{
	if(year<rd.year){
		return true;
	}
	else if(year==rd.year){
		if(month<rd.month){
			return true;
		}
		else if(month==rd.month){
			return day<rd.day;
		}
	}
	return false;
}
int main()
{
	MyDate date;
	int t;
	cin>>t;
	while(t--){
		int y,m,d;
		cin>>y>>m>>d;
		MyDate datee(y,m,d);
		if(date.Before(datee)){
			date.print();
			cout<<" before ";
			datee.print();
			cout<<endl;
		}
		else{
			datee.print();
			cout<<" before ";
			date.print();
			cout<<endl;
		}
	}
	return 0;
}



/*******************************************/
//main end 
