#include<iostream>
#include<cstring>
using namespace std;
int isNumber(char *a){
	int len=strlen(a);
	int sum=0;
	for(int i=0;i<len;i++){
		if(a[i]<'0'||a[i]>'9'){
			return -1;
		}
		sum=sum*10+(a[i]-'0');
	}
	return sum;
}
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		char a[100];
		cin.getline(a,sizeof(a));
		cout<<isNumber(a)<<endl; 
	}
	return 0;
}
