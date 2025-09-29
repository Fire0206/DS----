#include<iostream>
#include<cmath>
using namespace std;
class Point{
private:
	int x,y;
public:
	Point(){
		x=0;
		y=0;
	}
	Point(int x1,int y1){
		x=x1;
		y=y1;
	}
	~Point(){
		x=0;
		y=0;
		cout<<"point clear"<<endl;
	}
	void setXY(int x1,int y1){
		x=x1;
		y=y1;
	}
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}	
};
class Circle{
private:
	int x,y,r;
public:
	Circle(int x1,int y1,int r1){
		x=x1;
		y=y1;
		r=r1;
	}
	~Circle(){
		x=0;
		y=0;
		r=0;
		cout<<"circle clear"<<endl;
	}
	void Contain(int x1,int y1){
		if(sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))<=r){
			cout<<"in"<<endl;
		}
		else{
			cout<<"out"<<endl;
		}	
	}
};
int main(){
	int x,y,r;
	cin>>x>>y;
	Point p(x,y);
	int n;
	cin>>n;
	Point *points=new Point[n];
	for(int i=0;i<n;i++){
		cin>>x>>y;
		points[i].setXY(x,y);
	}
	cin>>x>>y>>r;
	Circle c(x,y,r);
	c.Contain(p.getX(),p.getY());
	for(int i=0;i<n;i++){
		c.Contain(points[i].getX(),points[i].getY());
	}
	return 0;	
}
