#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int* a=new int[n];
		for(int i=0;i<n;++i){
			cin>>*(a+i);
		}
		int sum1=0;
		int sum2=0;
		int b=1;
		for(int i=0;i<n;i++){
			sum2+=a[i];
		}
		for(int i=0;i<n;i++){
			if(sum1==sum2){
				cout<<(i-1)<<endl;
				b=0;
			}
			sum1+=a[i];
			sum2-=a[i];
		}
		if(b==1){
			cout<<"no"<<endl;
		}
		delete[] a;
	}
	return 0;
}
