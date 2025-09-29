#include<iostream>
#include<string>
using namespace std;
class Student {
private:
	//静态数据count，初始为0
	static int count;
public:
	Student(); //构造函数，创建一个学生对象，count+1
	~Student(); //析构函数，销毁一个学生对象，count-1
	static int getCount(); //count的get方法
};
//类外实现成员函数
//类外初始化静态数据成员count

/********** Write your code here! **********/
int Student::count = 0;
Student::Student() {
	count++;
}
Student::~Student() {
	if (count > 0) {
        count--;
    }
}
int Student::getCount() {
	return count;
}



/*******************************************/
//主函数
int main() {
	string op;
	int n;
	cin >> n;
	Student* st = NULL;
	while (n--) {
		cin >> op;
		if (op == "enter")
			st = new Student;  //学生进入校园，创建学生对象
		if (op == "leave")
			delete st;  //学生离开校园，销毁学生对象
	}
	cout << Student::getCount() << endl;
	return 0;
}

