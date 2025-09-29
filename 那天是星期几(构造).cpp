#include<iostream>
#include<string>
using namespace std;
class CDate
{
public:
	void print();
	void getWeekofDay();
	void getYMD(int a,int b,int c);
private:
	int month;
	int day;
	int year;
	int week;
};
void CDate::getYMD(int a,int b,int c){
	year=a;
	month=b;
	day=c;
}
void CDate::print(){
	cout<<month<<"/"<<day<<"/"<<year;
}
void CDate::getWeekofDay(){
	if(month==1||month==2){
		month+=12;
		year-=1;
	}
	week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7 + 1;
	string weekdays[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	cout<<", "<<weekdays[week-1]<<endl;
}
int main()
{
	int t,a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		CDate date;
		date.getYMD(a,b,c);
		date.print();
		date.getWeekofDay();
	}
	return 0;
}
