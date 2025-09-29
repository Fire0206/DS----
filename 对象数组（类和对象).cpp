#include<iostream>
#include<string>
using namespace std;
class Student{
	public:
	void get(){
		cin>>name>>id>>sex>>school>>number;
	}
	void print(){
		cout<<name<<endl;
	}
	
	private:
	string name;
	string id;
	string sex;
	string school;
	string number;	
};
int main(){
	int t;
	cin>>t;
	cin.ignore();
	Student *stu=new Student[t];
	for(int i=0;i<t;i++){
		stu[i].get();
		cin.ignore();
	}
	for(int i=0;i<t;i++){
		stu[i].print();
	}
	delete[] stu;
	return 0;
}
