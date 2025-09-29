#include<iostream>
using namespace std;
class Complex {
	float Real, Image;
public:
	Complex(float x = 0, float y = 0) {
		Real = x;
		Image = y;
	}
	friend Complex operator+(Complex& c1, Complex& c2);
	friend Complex operator-(Complex& c1, Complex& c2);
	friend Complex operator*(Complex& c1, Complex& c2);
	void show() {
		cout << "Real=" << Real << " " << "Image=" << Image << endl;
	}
};
Complex operator+(Complex& c1, Complex& c2) {
	Complex temp;
	temp.Real = c1.Real + c2.Real;
	temp.Image = c1.Image + c2.Image;
	return temp;
}
Complex operator-(Complex& c1, Complex& c2) {
	Complex temp;
	temp.Real = c1.Real - c2.Real;
	temp.Image = c1.Image - c2.Image;
	return temp;
}
Complex operator*(Complex& c1, Complex& c2) {
	Complex temp;
	temp.Real = c1.Real*c2.Real- c1.Image*c2.Image;
	temp.Image = c1.Image*c2.Real +c1.Real*c2.Image;
	return temp;
}
int main() {
	int x, y;
	cin >> x >> y;
	Complex c1(x, y);
	cin >> x >> y;
	Complex c2(x, y);
	Complex c3 = c1 + c2;
	c3.show();
	c3 = c1 - c2;
	c3.show();
	c3 = c1 * c2;
	c3.show();
	return 0;
}