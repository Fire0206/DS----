#include<iostream>
using namespace std;
class Fraction {
	int numerator, denominator;
	int common_division() {

	}
	void contracted() {

	}
public:
	Fraction() {
		numerator = 0;
		denominator = 1;
	}
	Fraction(int a ,int b) {
		numerator = a;
		denominator = b;
	}
	Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}
	Fraction operator+(Fraction f) {
		Fraction temp;
		temp.denominator = denominator * f.denominator;
		temp.numerator = numerator * f.denominator + denominator * f.numerator;
		return temp;
	}
	Fraction operator-(Fraction f) {
		Fraction temp;
		temp.denominator = denominator * f.denominator;
		temp.numerator = numerator * f.denominator - denominator * f.numerator;
		return temp;
	}
	Fraction operator*(Fraction f) {
		Fraction temp;
		temp.denominator = denominator * f.denominator;
		temp.numerator = numerator * f.numerator;
		return temp;
	}
	Fraction operator/(Fraction f) {
		Fraction temp;
		temp.denominator = denominator * f.numerator;
		temp.numerator = numerator * f.denominator;
		return temp;
	}
	void display() {
		cout << "fraction=" << numerator << "/" << denominator << endl;
	}
};
int main() {
	int a, b;
	cin >> a >> b;
	Fraction f1(a, b);
	cin >> a >> b;
	Fraction f2(a, b);
	Fraction f3 = f1 + f2;
	f3.display();
	f3 = f1 - f2;
	f3.display();
	f3 = f1 * f2;
	f3.display();
	f3 = f1 / f2;
	f3.display();
	return 0;
}