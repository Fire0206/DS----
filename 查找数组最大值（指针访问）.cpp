#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int *p=a;
		int max=*p;
		for(int i=1;i<n;i++){
			if(*p>max){
				max=*p;
			}
			p++;
		}
		cout<<max<<endl; 
	}
	return 0;
}
