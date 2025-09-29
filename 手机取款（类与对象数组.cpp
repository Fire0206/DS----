#include<iostream>
using namespace std;
class Card{
private:
	int id,number,code,balance;
public:
	Card(){
		
	}
	Card(int a,int b,int c,int d):
		id(a),number(b),code(c),balance(d){}
	int getId(){
		return id;
	}
	int getNumber(){
		return number;
	}
	int getcode(){
		return code;
	}
	int getBalance(){
		return balance;
	}
	bool checkCode(int tryCode){
		return code==tryCode;
	}
	void take(int takeout){
		if(takeout>balance){
			cout<<"¿¨ºÅ"<<id<<"--Óà¶î²»×ã"<<endl;
		}
		else{
			balance-=takeout;
			cout<<"¿¨ºÅ"<<id<<"--Óà¶î"<<balance<<endl; 
		}
	} 
};
int main(){
	int n;
	cin>>n;
	Card cards[100];
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		cards[i]=Card(a,b,c,d);
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int number,code,takeout;
		cin>>number>>code>>takeout;
		bool found=false;
		for(int j=0;j<n;j++){
			if(cards[j].getNumber()==number){
				found=true;
				if(cards[j].checkCode(code)){
					cards[j].take(takeout);
				}
				else{
					cout<<"ÃÜÂë´íÎó"<<endl;
				}
				break;
			}
		}
		if(!found){
			cout<<"ÊÖ»úºÅ²»´æÔÚ"<<endl;
		}
	}
	return 0;
}
