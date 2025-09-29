#include<iostream>
#include<string>
using namespace std;
class Teacher
{
	public:
	void get()
	{
		cin>>name>>sex>>major>>work1>>work2>>level>>address>>number;
	}
	void print()
	{
		cout<<name<<" "<<sex<<" "<<major<<" "<<work1<<" "<<work2<<" "<<level<<" "<<address<<" "<<number<<endl;
	}
	private:
	string name;
	string sex;
	string major;
	string work1;
	string work2;
	string level;
	string address;
	string number;
};
int main()
{
	int n;
	cin>>n;
	Teacher *p=new Teacher[n];
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

