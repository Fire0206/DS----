#include<iostream>
#include<string>
using namespace std;
int main(){
	int a;
	cin>>a;
	int b;
		b=a/100;
		for(int i=0;i<b;i++){
			cout<<"B";
		}
		b=(a%100)/10;
		for(int i=0;i<b;i++){
			cout<<"S";
		}
		b=a%10;
		for(int i=1;i<=b;i++){
			cout<<i;
		}
	return 0;
}
