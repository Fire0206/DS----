#include<iostream>
using namespace std ;
int main(){
	int t;
	cin>>t;
	while(t--){
		int N;
		int sum=0;
		cin>>N;
		for(int i=1;i<=N;i++){
			if((i%3!=0) && (i%4!=0)&& (i%7==0)){
				sum+=1;
			}
		}
		cout<<sum<<endl; 
	}
	return 0;
}
