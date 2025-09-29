#include<iostream>
#include<cstring>
using namespace std;
class CTelNumber{
private:
	char *num;
public:
	CTelNumber(){
		num=new char[8];
	}
	CTelNumber(char *a){
		num=new char[8];
		strcpy(num,a);
	}
	CTelNumber(const CTelNumber &c){
		num=new char[9];
		if(c.num[0]=='2'||c.num[0]=='3'||c.num[0]=='4'){
			num[0]='8';
		}
		else{
			num[0]='2';
		}
		for(int i=0;i<7;i++){
			num[i+1]=c.num[i];
		}
	}
	~CTelNumber(){
		delete num;
	}
	void print(){
		for(int i=0;i<8;i++){
			cout<<num[i];
		}
		cout<<endl;
	}
};
bool isLegal(char c[]){
	if(c[0]<'2'||c[0]>'8'){
		return false;
	}
	for(int i=1;i<7;i++){
		if(c[i]<'0'||c[i]>'9'){
			return false;
		}
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		char *c=new char[8];
		cin>>c;
		if(!isLegal(c)){
			cout<<"Illegal phone number"<<endl; 
		}
		else{
			CTelNumber num1(c);
			CTelNumber num2(num1);
			num2.print();
		}
	}
	return 0;
}
