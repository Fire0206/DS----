#include<iostream>
#include<string>
using namespace std;
class Actor {
protected:
	string name;
	int age;
public:
	Actor(string n,int a):name(n),age(a){}
	virtual void perform() = 0;
	virtual ~Actor(){}
};
class King :public Actor {
public:
	King(string n,int a):Actor(n,a){}
	void perform() {
		cout << "Hello, my name is " << name << ". I am " << age << ". I am the King." << endl;
	}
};
class Queen :public Actor {
public:
	Queen(string n, int a) :Actor(n, a) {}
	void perform() {
		cout << "Hello, my name is " << name << ". I am " << age << ". I am the Queen." << endl;
	}
};
class Knight :public Actor {
public:
	Knight(string n, int a) :Actor(n, a) {}
	void perform() {
		cout << "Hello, my name is " << name << ". I am " << age << ". I am a Knight." << endl;
	}
};
int main() {
	int t;
	cin >> t;
	string name,type;
	int age;
	Actor* a = nullptr;
	while (t--) {
		cin >> type>>name>>age;
		if (type == "King") {
			a = new King(name, age);
			a->perform();
		}
		else if (type == "Queen") {
			a = new Queen(name, age);
			a->perform();
		}
		else if (type == "Knight") {
			a = new Knight(name, age);
			a->perform();
		}
		else {
			cout << "There is no " << type << "." << endl;
		}
		
	}
	delete a;
	return 0;
}