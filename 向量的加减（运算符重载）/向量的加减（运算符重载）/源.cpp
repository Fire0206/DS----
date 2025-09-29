#include<iostream>
using namespace std;
class Vector {
	int vec[5];
public:
	Vector(int v[]) {
		for (int i = 0;i < 5;i++) {
			vec[i] = v[i];
		}
	}
	Vector() {};

	Vector(const Vector& obj) {
		for (int i = 0;i < 5;i++) {
			vec[i] = obj.vec[i];
		}
	}

	Vector operator +(const Vector& obj) {
		Vector temp;
		for (int i = 0;i < 5;i++) {
			temp.vec[i] = vec[i] + obj.vec[i];
		}
		return temp;
	}

	Vector operator -(const Vector& obj) {
		Vector temp;
		for (int i = 0;i < 5;i++) {
			temp.vec[i] = vec[i] - obj.vec[i];
		}
		return temp;
	}

	void print() {
		for (int i = 0;i < 5;i++) {
			cout << vec[i];
			if (i != 4) {
				cout << " ";
			}
		}
	}
};
int main() {
	int v1[5];
	int v2[5];
	for (int i = 0;i < 5;i++) {
		cin >> v1[i];
	}
	for (int i = 0;i < 5;i++) {
		cin >> v2[i];
	}
	Vector vec1(v1);
	Vector vec2(v2);
	Vector vec3 = vec1 + vec2;
	Vector vec4 = vec1 - vec2;
	vec3.print();
	cout <<" " << endl;
	vec4.print();
	cout << " ";
	return 0;
}
