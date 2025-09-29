#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Point
{
	double x,y;
public:
	Point();
	Point(double x_value,double y_value);
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point p); 
};
Point::Point()
{
	x=0;
	y=0;
}
Point::Point(double x_value,double y_value)
{
	x=x_value;
	y=y_value;
}
void Point::setX(double x_value)
{
	x=x_value;
}
void Point::setY(double y_value)
{
	y=y_value;
}
double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}
double Point::distanceToAnotherPoint(Point p)
{
	double len;
	len=sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
	return len;
}
int main()
{
	int t;
	cin>>t;
	Point p1,p2;
	double x1,x2,y1,y2,length;
	for(int i=0;i<t;i++){
		cin>>x1>>y1>>x2>>y2;
		p1.setX(x1);
		p1.setY(y1);
		p2.setX(x2);
		p2.setY(y2);
		length=p1.distanceToAnotherPoint(p2);
		cout<<"Distance of Point("<<fixed<<setprecision(2)<<p1.getX()<<","
		<<fixed<<setprecision(2)<<p1.getY()<<")";
		cout<<" to Point("<<fixed<<setprecision(2)<<p2.getX()<<","<<fixed<<
		setprecision(2)<<p2.getY()<<")";
		cout<<" is "<<fixed<<setprecision(2)<<length<<endl; 
	}
	return 0;
}
