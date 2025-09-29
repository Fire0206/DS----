#include<iostream>
#include<string>
using namespace std;
class Vehicle {
protected:
	string no;//编号

public:
	Vehicle(string n) :no(n){}
	virtual void display() = 0;//应收费用

};

class Car :public Vehicle {
protected:
	int people, weight;
public:
	Car(string n,int p, int w):Vehicle(n),people(p),weight(w){}
	void display() {
		cout << no <<" " << people * 8 + weight * 2<<endl;
	}
};

class Truck :public Vehicle {
protected:
	int weight;
public:
	Truck(string n, int w) :Vehicle(n), weight(w) {}
	void display() {
		cout << no << " " << weight * 5 << endl;
	}
};

class Bus :public Vehicle {
	int people;
public:
	Bus(string n, int p) :Vehicle(n),people(p) {}
	void display() {
		cout << no << " " << people * 3  << endl;
	}
};

int main() {
	int t;
	cin >> t;
	Vehicle* pv = nullptr;
	while (t--) {
		int type,people,weight;
		string no;
		cin >> type>>no;
		if (type == 1) {
			cin >> people >> weight;
			pv = new Car(no,people, weight);
			pv->display();
		}
		else if (type == 2) {
			cin >> weight;
			pv = new Truck(no, weight);
			pv->display();
		}
		else if (type == 3) {
			cin >> people;
			pv = new Bus(no, people);
			pv->display();
		}
	}
	return 0;
}