#include <iostream>
#include <string>
#include <map>
using namespace std;

// 日期类
class CDate
{
	int year, month, day;

public:
	CDate(int y, int m, int d) : year(y), month(m), day(d) {}
	void print()
	{
		cout << year << "." << month << "." << day << endl;
	}
};

// 手机类
class CPhone
{
	char type;			   // 类型，A表示机构，B表示企业、C表示个人, D表示备份
	string number;		   // 电话号码，11位整数
	int state;			   // 状态，1、2、3分别表示在用、未用、停用
	CDate *date = NULL; // 停机日期
public:
	// 析构函数
	~CPhone()
	{
		if (date)
		{
			delete date;
		}
	}
    // 补齐CPhone的构造函数，拷贝构造函数，输出函数print，停机函数shutdown
    
/********** Write your code here! **********/
	CPhone(char a,string b,int c):type(a),number(b),state(c){
		cout<<"Construct a new phone "<<number<<endl;
	}
	CPhone(const CPhone &phone){
		state=phone.state;
		date=phone.date;
		type='D';
		number=phone.number;
		cout<<"Construct a copy of phone "<<number<<endl;
		number+='X';
	}
	void shutdown(CDate d){
		
		state=3;
		date = new CDate(d);
		cout<<"Stop the phone "<<number<<endl;
		print();
	}
	void print(){
		string typeStr;
        switch(type) {
            case 'A': typeStr = "机构"; break;
            case 'B': typeStr = "企业"; break;
            case 'C': typeStr = "个人"; break;
            case 'D': typeStr = "备份"; break;
        }
        
        string stateStr;
        switch(state) {
            case 1: stateStr = "在用"; break;
            case 2: stateStr = "未用"; break;
            case 3: stateStr = "停用"; break;
        }
        
        cout << "类型=" << typeStr << "||号码=" << number << "||State=" << stateStr;
        if (date && state == 3) {
            cout << "||停机日期=";
            date->print();
        }
	}
};

/*******************************************/
// 主函数
int main()
{
	int t;
	char type;	   // 类型，A表示机构，B表示企业、C表示个人, D表示备份
	string number; // 电话号码
	int state;	   // 状态，1、2、3分别表示在用、未用、停用
	int year, month, day;  // 停机日期
	cin >> t;

	while (t--)
	{
		cin >> type >> number >> state >> year >> month >> day;

		CPhone phone(type, number, state); // 构造函数构建对象
		phone.print();					   // 输出对象，见样例
		cout << endl;
		CPhone copyphone(phone); // 拷贝构造对象
		copyphone.print();		 // 输出对象，见样例
		cout << endl;
		phone.shutdown(CDate(year, month, day)); // 停机，输出
		cout << "----" << endl;
	}
	return 0;
}
