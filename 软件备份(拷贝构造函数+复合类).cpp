#include<iostream>
#include<string>
using namespace std;
class CDate
{
private:
int year, month, day;
public:
CDate(int y, int m, int d) { year = y; month = m; day = d; }
bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
int getYear() { return year; }
int getMonth() { return month; }
int getDay() { return day; }
int getDayofYear()         //计算日期从当年1月1日算起的天数
{
int i, sum=day;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

if (isLeapYear())   a[2]=29;

for(i=1;i<month;i++)   sum +=a[i];

return sum;
}
};
class Software{
	string name;
	string type;
	CDate date;
	string media;
public:
	Software(const Software& s) : 
	name(s.name), type("B"), date(s.date), media("H") {}
	
	Software(string a,string b,CDate c,string d):
		name(a),type(b),date(c),media(d){}
		
	void print(){
		if(type=="O") type="original";
		else if(type=="B") type="backup";
		else type="trial";
		if(media=="D") media="optical disk";
		else if(media=="U") media="USB disk";
		else media="hard disk";
		cout<<"name:"<<name<<endl
			<<"type:"<<type<<endl
			<<"media:"<<media<<endl
			<<"this software ";
			if(date.getDay()==0&&date.getMonth()==0&&date.getYear()==0){
				cout<<"has unlimited use";
			}else if(date.getYear()>=2015&&(date.getMonth()>4||(date.getMonth()==4&&date.getDay()>7))){
					CDate temp(2015,4,7);
					int left=date.getDayofYear()-temp.getDayofYear();
					cout<<"is going to be expired in "<<left<<" days";
			}else{
				cout<<"has expired";
			}
			cout<<endl<<endl;
	}
};


int main()
{
	int t;
	string a,b,d;
	int y,m,day;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b>>d;
		cin>>y>>m>>day;
		CDate c(y,m,day);
		Software s1(a,b,c,d);
		s1.print();
		Software s2(s1);
		s2.print();
	}
	return 0;
}

