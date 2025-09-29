#include<iostream>
using namespace std;
void swap1(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void swap2(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
int main(){
	int a,b;
	cin>>a>>b;
	swap1(&a,&b);
	cout<<"swap1:"<<a<<" "<<b<<endl;
	swap2(a,b);
	cout<<"swap2:"<<a<<" "<<b<<endl;
	return 0;
} 
