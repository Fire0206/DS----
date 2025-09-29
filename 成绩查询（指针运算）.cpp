#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		int n;
		cin>>n;
		int arr[1000];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int* p=arr+n/2;
		int* rp=p;
		++rp;
		int* lp=p;
		--lp;
		cout<<*lp<<" "<<*rp<<endl;
		int b;
		cin>>b;
		int distance=b-(n/2+1);
		cout<<*(p+distance);
		if(j!=(t-1)){
			cout<<endl;
		}
	}
	return 0;
} 
