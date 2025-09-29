#include<iostream>
#include<string>
using namespace std;
class Student
{
	public:
	void get()
	{
		cin>>name>>id>>major1>>major2>>sex>>address>>number;
	}
	void print()
	{
		cout<<name<<" "<<id<<" "<<major1<<" "<<major2<<" "<<sex<<" "<<address<<" "<<number<<endl;
	}
	private:
	string name;
	string id;
	string major1;
	string major2;
	string sex;
	string address;
	string number;
};
int main()
{
	int n;
	cin>>n;
	Student *p=new Student[n];
	for(int i=0;i<n;i++)
	{
		p[i].get();	
	}
	for(int i=0;i<n;i++){
		p[i].print();
	} 
	delete []p;
	return 0;
}

