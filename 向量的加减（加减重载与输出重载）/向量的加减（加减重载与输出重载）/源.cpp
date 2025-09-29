#include<iostream>
using namespace std;
class Vector {
	int x[10];
	friend ostream& operator<<(ostream& cout, Vector& v);
public:
	Vector(){}
	Vector(int x1[])
	{
		for (int i = 0;i < 10;i++) {
			x[i] = x1[i];
		}
	}
	Vector operator+(Vector& v) {
		Vector temp;
		for (int i = 0;i < 10;i++) {
			temp.x[i]=x[i] + v.x[i];
		}
		return temp;
	}
	Vector operator-(Vector& v) {
		Vector temp;
		for (int i = 0;i < 10;i++) {
			temp.x[i] = x[i] - v.x[i];
		}
		return temp;
	}
};
ostream& operator<<(ostream& cout, Vector& v) {
	for (int i = 0;i < 10;i++) {
		cout << v.x[i];
		if (i != 9) {
			cout << " ";
		}
	}
	return cout;
}
int main() {
	int x[10], y[10];
	for (int i = 0;i < 10;i++) {
		cin >> x[i];
	}
	for (int i = 0;i < 10;i++) {
		cin >> y[i];
	}
	Vector v1(x);
	Vector v2(y);
	Vector v3 = v1 + v2;
	Vector v4 = v1 - v2;
	cout << v3 << endl;
	cout << v4 << endl;
	return 0;
}