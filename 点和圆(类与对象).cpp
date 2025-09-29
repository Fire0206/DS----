#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Point{
private:
	int x;
	int y;
public:
	void SetPoint(Point &p){
		cin>>p.x>>p.y;
	}
	
	int GetX(){
		return x;
	}
	int GetY(){
		return y;
	}
};
class Circle{
public:
	int x;
	int y;
	int r;


public:
	void SetCenter(Circle &c){
		cin>>c.x>>c.y;
	}
	void SetRadius(Circle &c){
		cin>>c.r;
	}
	double getArea(Circle &c){
		return 3.14*c.r*c.r;
	}
	double getLength(Circle &c){
		return 3.14*2*c.r;
	}
	bool Contain(Circle &c,Point &p){
		return sqrt((c.x-p.GetX())*(c.x-p.GetX())+(c.y-p.GetY())*(c.y-p.GetY()))<c.r;
	}
};
int main(){
	Circle c;
	c.SetCenter(c);
	c.SetRadius(c);
	Point p;
	p.SetPoint(p);
	cout<<fixed<<setprecision(2)<<c.getArea(c)<<
	" "<<fixed<<setprecision(2)<<c.getLength(c)<<endl;
	if(c.Contain(c,p)){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
	return 0;
}
