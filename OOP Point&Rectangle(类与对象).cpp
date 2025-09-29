#include<iostream>
using namespace std;
class Point{
public:
	double x;
	double y;
};

class Rectangle{
public:
	double x;
	double y;
	double length;
	double width;
};
bool check(Point p,Rectangle re){
	return (p.x-re.x)*(p.x-re.x)<=re.length*re.length/4 &&(p.y-re.y)*(p.y-re.y)<=re.width*re.width/4;
}
int main(){
	Rectangle re;
	cin>>re.x>>re.y>>re.length>>re.width;
	int n;
	cin>>n;
	Point *points=new Point[n];
	for(int i=0;i<n;i++){
		cin>>points[i].x>>points[i].y;
		if(check(points[i],re)){
			cout<<"inside"<<endl;
		}
		else{
			cout<<"outside"<<endl;
		}
	}
	cout<<"after move the centre of rectangle:"<<endl;
	cin>>re.x>>re.y;
	for(int i=0;i<n;i++){
		if(check(points[i],re)){
			cout<<"inside";
		}
		else{
			cout<<"outside";
		}
		if(i!=n-1){
			cout<<endl;
		}
	}
	delete[] points;
	return 0;
}
