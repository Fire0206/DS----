#include<iostream>
using namespace std;
class CComplex {
	double r, i;
public:
	friend istream& operator>>(istream& cin , CComplex& p);
	friend ostream& operator<<(ostream& cout, CComplex& p);
};
istream& operator>>(istream& cin, CComplex& p) {
	cin >> p.r >> p.i;
	return cin;
}
ostream& operator<<(ostream& cout, CComplex& p) {
	if (p.i == 0 && p.r == 0) {
		cout << 0;
	}
	else if (p.i == 0&&p.r!=0) {
		cout << p.r;
	}
	else if (p.r == 0&&p.i!=0) {
		cout << p.i << "i";
	}
	else if (p.i > 0) {
		cout << p.r << "+" << p.i << "i";
	}
	else if (p.i < 0) {
		cout << p.r << p.i << "i";
	}
	cout << endl;
	return cout;
}

int main()
{
	int n;
	double r, i;
	CComplex x;
	cin >> n;
	while (n--) {
		cin >> x;
		cout << x;
	}
	return 0;
}