#include<iostream>
#include<cstring>
using namespace std;
class Student
{
public:
	Student(char *pname)
	{
		cout << "Constructing " << pname << endl;
		name = new char[strlen(pname) + 1];
		if (name != NULL)
			strcpy(name, pname);
	}
	Student(const Student &s);
	~Student();

protected:
	char *name;
};
/********** Write your code here! **********/
Student::~Student(){
	cout<<"Destructing "<<name<<endl;
	delete[] name;
}
Student::Student(const Student &s){
	name = new char[strlen(s.name) + 1];
	if (name != NULL)
		strcpy(name, s.name);
	cout<<"Copying of "<<name<<endl;
}


/*******************************************/
int main()
{
	char name[10];
	cin >> name;
	Student s1(name);
	Student s2 = s1;
    return 0;
}
