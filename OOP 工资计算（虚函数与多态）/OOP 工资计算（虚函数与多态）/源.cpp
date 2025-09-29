#include<iostream>
using namespace std;
class employee {
protected:
	string name;
	string type;
	int workDay, overDay;
public:
	employee(string na,string ty,int wo,int ov):name(na),type(ty),workDay(wo),overDay(ov){}
	virtual int wage() {
		return (1500 + 100 * workDay + 150 * overDay);

	}
};
class exec :public employee {
public:
	exec(string na, string ty, int wo, int ov):employee(na,ty,wo,ov){}
	int wage() {
		return (5000 + 200 * workDay + 300 * overDay);
	}
};
class manage :public employee {
public:
	manage(string na, string ty, int wo, int ov) :employee(na, ty, wo, ov) {}
	int wage() {
		return (10000 + 300 * workDay + 500 * overDay);
	}
};
int main() {
	int t;
	cin >> t;
	string name;
	string type;
	int workDay, overDay;
	employee *em = nullptr;
	while (t--) {
		cin >> name >> type >> workDay >> overDay;
		if (type == "Employee") {
			em = new employee(name, type, workDay, overDay);
		}
		else if(type=="Director") {
			em = new exec(name, type, workDay, overDay);
		}
		else {
			em = new manage(name, type, workDay, overDay);
		}
		cout << em->wage() << endl;
	}
	return 0;
}

