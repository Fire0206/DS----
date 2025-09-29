#include<iostream>
using namespace std;
class Complex
{
private:
	int real;
	int image;
public:
	Complex() {
		real = 1;
		image = 1;
	}
	Complex(int r,int i):real(r),image(i){}
	Complex add(const Complex& c) {
		Complex temp;
		temp.image = image + c.image;
		temp.real = real + c.real;
		return temp;
	}
	Complex minus(const Complex& c) {
		Complex temp;
		temp.image = image - c.image;
		temp.real = real - c.real;
		return temp;
	}
	friend ostream& operator<<(ostream& os,const Complex& c) {
		if (c.image == 0 && c.real == 0) {
			os << 0;
		}
		else if(c.image != 0 && c.real == 0){
			os << c.image << "i";
		}
		else if (c.image == 0 && c.real != 0) {
			os << c.real;
		}
		else if (c.image == 1 && c.real != 0) {
			os << c.real << "+i";
		}
		else if (c.image > 0 && c.real != 0) {
			os << c.real << "+" << c.image << "i";
		}
		else {
			os << c.real  << c.image << "i";
		}
		return os;
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		int r1, r2, i1, i2;
		cin >> r1 >> i1 >> r2 >> i2;
		Complex c1(r1,i1), c2(r2,i2);
		Complex c3 = c1.add(c2);
		Complex c4 = c1.minus(c2);
		cout << "sum:" << c3 << endl;
		cout << "remainder:" << c4 << endl;
	}
	return 0;
}