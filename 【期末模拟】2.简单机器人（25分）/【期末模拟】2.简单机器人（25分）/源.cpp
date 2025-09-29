#include<iostream>
using namespace std;
class CRobotI {
protected:
	string name;
	int step;
public:
	CRobotI(string n, int s) :name(n), step(s) {}
	void walk(int m) {
		step += m;
	}
	virtual void print() {
		cout << "CRobotI " << name << " says: I am at " << step << endl;
	}
	virtual ~CRobotI(){}
};
class CRobotII :public CRobotI {
private:
	int layer;
public:
	CRobotII(string n, int s,int l) :CRobotI(n,s), layer(l) {}
	void jump(int m) {
		layer += m*2;
	}
	void print() {
		cout << "CRobotII " << name << " says: I am at " << step <<" on layer "<<layer << endl;
	}
};
int main() {
	int t;
	cin >> t;
	int step, layer,m;
	string name;
	
	while (t--) {
		cin >> name >> step >> layer>>m;
		CRobotI c1(name, step);
		c1.walk(m);
		c1.print();
		CRobotII c2(name, step, layer);
		c2.walk(m);
		c2.jump(m);
		c2.print();
		cout << endl;
	}
	return 0;
}