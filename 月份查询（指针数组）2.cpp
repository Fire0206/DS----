#include<iostream>
#include<string>
using namespace std;
int main(){
	string *arr[12]={January,Febuary,March,April,May,June,July,August,September,October,November,December};
	int t;
	cin>>t;
	while(t--){
		int i;
		cin>>i;
		if(i<=0||i>12){
			cout<<"error"<<endl;
		}
		else{
			cout<<*arr[i-1]<<endl;
		}
	}
	return 0;
} 
