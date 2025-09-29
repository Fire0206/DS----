#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
class CTriangle{
private:
	string type;
	double a;
	double b;
	double c;
public:
	CTriangle(){
		a=0;
		b=0;
		c=0;
	}
	CTriangle(double a1,double b1,double c1){
		a=a1;
		b=b1;
		c=c1;
		double limit=0.01;
		double a2=a*a;
		double b2=b*b;
		double c2=c*c;
		if((a+b<=c)||(a+c<=b)||(b+c<=a)){
			type="no triangle";
		}else{
			if(a==b==c){
				type="equilateral triangle";
			}
			else if(a==b||a==c||b==c){
				if(abs(a2+b2-c2)<limit||abs(a2+c2-b2)<limit||abs(c2+b2-a2)<limit){
					type="isosceles right triangle";
				}
				else{
					type="isosceles triangle";
				}
			}
			else if(abs(a2+b2-c2)<limit||abs(a2+c2-b2)<limit||abs(c2+b2-a2)<limit){
				type="right triangle";
			}
			else{
				type="general triangle";
			}
		}
	}
	~CTriangle(){
		a=0;
		b=0;
		c=0;
		type="none";
	}
	double area(){
		double p=(a+b+c)/2;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
	string getType(){
		return type;
	}
};
int main()
{
	int t;
	double a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		CTriangle triangle(a,b,c);
		cout<<triangle.getType();
		if(triangle.getType()=="no triangle"){
			cout<<endl;
		}
		else{
			cout<<", "<<fixed<<setprecision(1)<<triangle.area()<<endl;
		}
	} 
	return 0;
} 
