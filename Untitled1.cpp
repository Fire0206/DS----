#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int t;
	cin>>t;
	int a,b,c;
	while(t--){
		cin>>a>>b>>c;
		int *o = &a;
		int *p = &b;
		int *q = &c;
		if(*o<*p) swap(o,p);
		if(*o<*q) swap(o,q);
		if(*p<*q) swap(p,q);
		cout<<*o<<" "<<*p<<" "<<*q<<" "<<endl;
	}
	return 0;
}
