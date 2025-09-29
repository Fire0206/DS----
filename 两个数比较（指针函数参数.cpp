#include<iostream>
using namespace std;
void cmp(int *p1,int *p2){
	if(*p1>*p2){
		int temp=*p1;
		*p1=*p2;
		*p2=temp;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int *p1=&a;
		int *p2=&b;
		cmp(p1,p2);
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}
