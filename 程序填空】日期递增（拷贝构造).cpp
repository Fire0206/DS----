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

	CDate(const CDate &other);


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
CDate::CDate(int y, int m, int d)
{
    year = new int(d);
    month = new int(m);
    day = new int(y);
}
CDate::CDate(const CDate &other) {

    year = new int(*other.year);
    month = new int(*other.month);
    day = new int(*other.day);

    (*day)++;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((*year % 4 == 0 && *year % 100 != 0) || (*year % 400 == 0)) {
        daysInMonth[2] = 29; 
    }

    if (*day > daysInMonth[*month]) {
        *day = 1;
        (*month)++;
        if (*month > 12) {
            *month = 1;
            (*year)++;
        }
    }
}



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

