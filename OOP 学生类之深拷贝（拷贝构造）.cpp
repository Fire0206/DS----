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
    Student(Student &s){
    	name=s.name;
    	cout<<"Copying of "<<s.name<<endl;
	}
    
    ~Student(){
    	cout<<"Destructing "<<name<<endl;
	}
 
protected:
    char *name;
};
int main()
{
    char name[10];
    cin>>name;
    Student s1(name);
    Student s2 = s1;
}
