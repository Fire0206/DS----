#include<iostream>
using namespace std;

class Person{
private:
	int value;
	
public:
	Person(){
		value=0;
		cout<<"Constructed by default, value = "<<value<<endl; 
	}
	Person(int a){
		value=a;
		cout<<"Constructed using one argument constructor, value = "<<value<<endl;
	}
	Person(const Person &p){
		value=p.value;
		cout<<"Constructed using copy constructor, value = "<<value;
	}
};
int main()
{
	int t,n,b;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==0){
			Person p;
		}else if(n==1){
			cin>>b;
			Person p(b);
		}else if(n==2){
			cin>>b;
			Person p(b);
			Person p2(p);
		}
	}
	return 0;
}
