#include<iostream>
using namespace std;

int main(){
	int a=10;
	int *p=&a;
	cout<<a<<endl;
	cout<<"aµÄµØÖ·Îª"<<p<<endl;
	*p=100;
	cout<<a<<endl;
	cout<<*p<<endl;
	return 0;
} 
