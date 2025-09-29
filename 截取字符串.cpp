#include<iostream>
#include<cstring>
using namespace std;
int substr(char str1[],char str2[],int index){
	int len=strlen(str1);
	if (index<0||index>=len){
		return 0;
	}
	int j=0;
    for(int i=index;i<len;++i) {
        str2[j++] = str1[i];
    }
    str2[j] = '\0';
    return 1;
	}
int main(){
	int n;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		char str1[30],str2[30];
		int index;
		cin.getline(str1,30);
		cin>>index;
		cin.ignore();
		if(substr(str1,str2,index)){
			cout<<str2<<endl;
		}
		else{
			cout<<"IndexError"<<endl;
		}
	}
	return 0;
}
