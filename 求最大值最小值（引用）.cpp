#include <iostream>
using namespace std;
void find(int *num,int n,int &minIndex,int &maxIndex){
	for(int j=0;j<n;j++){
		if(num[j]<num[minIndex]){
			minIndex=j;
		}
		if(num[j]>num[maxIndex]){
			maxIndex=j;
		}
	}
}
int main(){
	int t;
	cin>>t;
	for(int s=0;s<t;s++){
		int n;
		cin>>n;
		int *num=new int[100];
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		int minIndex=0;
		int maxIndex=0;
		find(num,n,minIndex,maxIndex);
		cout<<"min="<<num[minIndex]<<" "<<"minindex="<<minIndex<<endl;
		cout<<"max="<<num[maxIndex]<<" "<<"maxindex="<<maxIndex;
		if(s!=t-1){
			cout<<endl<<endl;
		}
		delete[] num;
	}
	return 0;
}
