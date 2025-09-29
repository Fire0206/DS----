#include<iostream>
#include<iomanip>
#include<cmath> 
using namespace std;
class CFraction
{
	int fz, fm;
	public:
	CFraction(int fz_val, int fm_val) ;
	CFraction add(const CFraction &r);
	CFraction sub(const CFraction &r);
	CFraction mul(const CFraction &r);
	CFraction div(const CFraction &r);
	int getGCD();  
	void print();
	CFraction(){};
};
CFraction::CFraction(int fz_val, int fm_val)
{
	fz=fz_val;
	fm=fm_val;
}  
CFraction CFraction::add(const CFraction &r)
{
	CFraction temp(fz*r.fm+r.fz *fm,fm*r.fm);
	int gcd=temp.getGCD();
	temp.fz=temp.fz/gcd;
	temp.fm=temp.fm/gcd;
	return temp;
}
CFraction CFraction::sub(const CFraction &r)
{
	CFraction temp((fz*r.fm-r.fz *fm),fm*r.fm);
	int gcd=temp.getGCD();
	temp.fz=temp.fz/gcd;
	temp.fm=temp.fm/gcd;
	return temp;
}
CFraction CFraction::mul(const CFraction &r)
{
	CFraction temp(fz*r.fz,fm*r.fm);
	int gcd=temp.getGCD();
	temp.fz=temp.fz/gcd;
	temp.fm=temp.fm/gcd;
	return temp;
}
CFraction CFraction::div(const CFraction &r)
{
	CFraction temp(fz*r.fm,r.fz *fm);
	int gcd=temp.getGCD();
	temp.fz=temp.fz/gcd;
	temp.fm=temp.fm/gcd;
	return temp;
}
int CFraction::getGCD()
{
	int r;
	int a,b;
	if(fabs(fz)>fabs(fm))
	{
		a=fabs(fz);
		b=fabs(fm);
	}
	else 
	{
		a=fabs(fm);
		b=fabs(fz);
	}
	while(a%b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return b;
}
void CFraction::print()
{
	if(fz<0&&fm>0||fz>0&&fm<0) cout<<'-';
	cout<<fabs(fz)<<'/'<<fabs(fm)<<endl;
}
int main()
{
	int t;
	cin>>t;
	int fz1,fm1,fz2,fm2;
	CFraction p3;
	while(t--)
	{
		char ch;
		cin>>fz1>>ch>>fm1>>fz2>>ch>>fm2;
		CFraction p1(fz1,fm1);
		CFraction p2(fz2,fm2);
		p3=p1.add(p2);
		p3.print();
		p3=p1.sub(p2);
		p3.print();
		p3=p1.mul(p2);
		p3.print();
		p3=p1.div(p2);
		p3.print();
		cout<<endl;		
	} 
	return 0;
}

