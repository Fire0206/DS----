#include<iostream>
using namespace std;
class Date{
public:
	int year,month,day;
	Date(int a,int b,int c):year(a),month(b),day(c)
	{}
};

class VIP{
public:
	int id;
	Date birth;
	VIP(int a,int b,int c,int d):
		id(a),birth(b,c,d){}
	double Discount(Date today){
		if(birth.month==today.month && birth.day==today.day){
			return 0.5;
		}else{
			return 0.95;
		}
	}
};

int main()
{
	int y,m,d,t,id;
	cin>>y>>m>>d;
	Date today(y,m,d);
	cin>>t;
	while(t--){
		cin>>id>>y>>m>>d;
		VIP vip(id,y,m,d);
		double con;
		cin>>con;
		con*=vip.Discount(today);
		cout<<vip.id<<"'s consumption is "<<int(con)<<endl;
		
	}
	return 0;
}
