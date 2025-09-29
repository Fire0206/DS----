#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class CPerson {
protected:
	string name,tele;
public:
	CPerson(string n, string t) {
		name = n;
		tele = t;
	}
};

class CStudent:public CPerson {
protected:
	int Atime[12];
public:
	CStudent(string n, string t,int a[]) :CPerson(n, t) {
		for (int i = 0;i < 12;i++) {
			Atime[i] = a[i];
		}
	}
	void check() {
		int sum = 0;
		for (int i = 0;i < 12;i++) {
			sum += min( 1,Atime[i]/60 );
		}
		if (sum >= 10) {
			cout << name << "达到学时要求可以预约！电话" << tele << endl;
		}
		else {
			cout << name << "未达到学时要求不能预约！电话" << tele << endl;
		}
	}

};
class CVip :public CStudent {
	int Btime[12];
public:
	CVip(string n, string t, int a[],int b[]) :CStudent(n,t,a) {
		for (int i = 0;i < 12;i++) {
			Btime[i] = b[i];
		}
	}
	void check(){
		int sum = 0;
		for (int i = 0;i < 12;i++) {
			sum += min( 1,Atime[i]/60 );
		}
		for (int i = 0;i < 12;i++) {
			sum += min(2, Btime[i]/60);
		}
		if (sum >= 10) {
			cout << name << "达到学时要求可以预约！电话" << tele << endl;
		}
		else {
			cout << name << "未达到学时要求不能预约！电话" << tele << endl;
		}
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		string type;
		string name, tele;
		cin >> type>>name>>tele;
		if (type == "F") {
			int Atime[12];
			for (int i = 0;i < 12;i++) {
				cin >> Atime[i];
			}
			CStudent stu(name, tele,Atime);
			stu.check();
		}

		else if (type == "V") {
			int Atime[12];
			for (int i = 0;i < 12;i++) {
				cin >> Atime[i];
			}
			int Btime[12];
			for (int i = 0;i < 12;i++) {
				cin >> Btime[i];
			}
			CVip vip(name, tele, Atime,Btime);
			vip.check();
		}

	}
	return 0;
}