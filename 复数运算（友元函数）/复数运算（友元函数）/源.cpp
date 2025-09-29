#include <iostream>
using namespace std;
class complex {
private:
	double real;
	double imag;
public:
	complex() {
		real = 0;
		imag = 0;
	}
	double getR() {
		return real;
	}
	double getI() {
		return imag;
	}
	complex(double r,double i):real(r),imag(i){}
	friend complex addCom(const complex& a, const complex& b);
	friend complex minusCom(const complex& a, const complex& b);
};
complex addCom(const complex& a, const complex& b) {
	complex temp;
	temp.real = a.real + b.real;
	temp.imag = a.imag + b.imag;
	return temp;
}
complex minusCom(const complex& a, const complex& b) {
	complex temp;
	temp.real = a.real - b.real;
	temp.imag = a.imag - b.imag;
	return temp;
}
int main() {
	double real;
	double imag;
	cin >> real >> imag;
	complex c1(real,imag);
	int t;
	cin >> t;
	char op;
	while (t--) {
		cin >> op>>real>>imag;
		complex c2(real, imag);
		if (op == '+') {
			c1 = addCom(c1, c2);
		}
		else {
			c1 = minusCom(c1, c2);
		}
		cout << "(" << c1.getR() << "," << c1.getI() << ")" << endl;
	}
	return 0;
}