#include<iostream>
using namespace std;
struct SPoint{
	int x;
	int y;
};
struct SLine{
	SPoint p1;
	SPoint p2;
};
void direction(const SLine &ab,const SPoint &c){
	SLine ac;
	ac.p1.x=ab.p1.x;
	ac.p1.y=ab.p1.y;
	ac.p2.x=c.x;
	ac.p2.y=c.y;
	int m=(ab.p2.x-ab.p1.x)*(ac.p2.y-ac.p1.y)-(ab.p2.y-ab.p1.y)*(ac.p2.x-ac.p1.x);
	if(m==0){
		cout<<"intersect"<<endl;
	}
	else if(m<0){
		cout<<"clockwise"<<endl;
	}
	else{
		cout<<"anti clockwise"<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		SLine ab;
		SPoint c;
		cin>>ab.p1.x>>ab.p1.y>>ab.p2.x>>ab.p2.y;
		cin>>c.x>>c.y;
		direction(ab,c);
	}
	return 0;
}
