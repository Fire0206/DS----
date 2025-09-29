#include<iostream>
#include<algorithm>
using namespace std;
bool judge(int a[],int b[]){
	sort(a,a+3);
	sort(b,b+3);
	for(int i=0;i<3;i++){
		if(a[i]<b[i]){
			return false;
		}
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int a[3],b[3];
		for(int j=0;j<3;j++){
			cin>>a[j];
		}
		for(int j=0;j<3;j++){
			cin>>b[j];
		}
		if(judge(a,b)||judge(b,a)){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
} 
