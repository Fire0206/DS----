#include<iostream>
#include<string>
using namespace std;
class Student {
protected:
	string name;
	string id;
public:
	Student(string na,string i):name(na),id(i){}
	virtual int fee() {
		return 2000;
	}
	virtual void display() {
		cout << name << " " << id << " " << fee()<<endl;
	}
};
class GraStu :public Student {
	string name2;
public:
	GraStu(string na, string i,string na2):Student(na,i),name2(na2){}
	int fee() {
		return 1000;
	}
	void display() {
		cout << name << " " << id << " " << name2<<" " << fee()<<endl;
	}
};
int main() {
	int t;
	cin >> t;
	string type;
	string name,name2;
	string id;
	Student* stu = nullptr;
	while (t--) {
		cin >> type;
		if (type == "S") {
			cin >> id >> name;
			stu = new Student(name, id);
			stu->display();
		}
		else {
			cin >> id >> name>>name2;
			stu = new GraStu(name, id,name2);
			stu->display();
		}
	}
	return 0;
}