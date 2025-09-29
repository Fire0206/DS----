#include<iostream>
#include<cstring>
using namespace std;
int compare(char *a,char *b){
	int len1=strlen(a);
	int len2=strlen(b);
	if(len1>len2){
		return 1;
	}if(len1<len2){
		return -1;
	}else{
		int maxSum=0;
		int minSum=0;
		for(int i=0;i<len1;i++){
			if(a[i]>b[i]){
				maxSum++;
			}else if(a[i]<b[i]){
				minSum++;
			}
		}
		if(maxSum>minSum){
			return 1;
		}else if(maxSum<minSum){
			return -1;
		}else{
			return 0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		char a[1000],b[1000];
		cin.getline(a,sizeof(a));
		cin.getline(b,sizeof(b));
		int result=compare(a,b);
		cout<<result<<endl;
	}
	return 0;
}
