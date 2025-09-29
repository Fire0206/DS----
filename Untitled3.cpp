//头文件区域
#include <iostream>
using namespace std;

// 日期类CDate
class CDate
{
	int *year,*month,*day;
public:
	CDate(int y,int m, int d);
	void print();
	~CDate();
    // 补齐CDate拷贝构造函数声明
/********** Write your code here! **********/
	CDate(const CDate &date;)



/*******************************************/
};

CDate::~CDate()
{
	delete year;
	delete month;
	delete day;
}

void CDate::print()
{
	cout << *year << "/" << *month << "/" << *day << endl;
}

// 补齐构造函数和拷贝构造函数实现

/********** Write your code here! **********/




/*******************************************/
//主函数
int main()
{	int a,b,c;
	cin>>a>>b>>c;
	CDate d1(a,b,c);
	CDate d2=d1;
	CDate d3(d2);
	d1.print();
	d2.print();
	d3.print();
	return 0;
}

