#include<iostream>
using namespace std;
class A {
public:
	A() {
		cout << "I am A"<<endl;
	}
};
class B {
public:
	B() {
		cout << "I am B" << endl;
	}
};
class P1 {
public:
	P1() {
		cout << "I am P1" << endl;
	}
};
class P2 {
public:
	P2() {
		cout << "I am P2" << endl;
	}
};
class P3 {
public:
	P3() {
		cout << "I am P3" << endl;
	}
};
class P4 {
public:
	P4() {
		cout << "I am P4" << endl;
	}
};
class Test :virtual public P2, virtual public P4, public P1, public P3 {
	A a;
	B b;
	
};
int main()
{
	cin.get();
	Test t;
}