#include<iostream>
#include<string>
using namespace std;
class CAccount{
private:	
	long account;
	string name;
	float balance;
	float in;
	float out;
	
public:
	void get(){
		cin>>account>>name>>balance>>in>>out;
	}
	
	void check(){
		cout<<name<<"'s balance is "<<balance<<endl;
	}
	
	void deposit(){
		balance+=in;
		cout<<"saving ok!"<<endl;
	}
	
	void withdraw(){
		if(out>balance) cout<<"sorry! over limit!"<<endl;
		else
		{
			balance-=out;
			cout<<"withdraw ok!"<<endl;
		 } 
	}
};
int main(){
	CAccount p[3];
	for(int i=0;i<2;i++){
		p[i].get();
	}
	for(int i=0;i<2;i++){
		p[i].check();
		p[i].deposit();
		p[i].check();
		p[i].withdraw();
		p[i].check();
	}
}
