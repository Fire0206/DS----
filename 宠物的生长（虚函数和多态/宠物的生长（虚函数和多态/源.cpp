#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class CDate {
protected:
	int y, m, d;
public:
	CDate(int yy, int mm, int dd) : y(yy), m(mm), d(dd) {
	}
	friend int getday(CDate& a, CDate& b);


};

class Pet {
protected:
	string name;
	float length;
	float weight;
	CDate current;
public:
	virtual void display(CDate day) = 0;
	Pet(string n, float l, float w, CDate c) : name(n), length(l), weight(w), current(c) {
	}
};



class Cat : public Pet {
public:
	virtual void display(CDate day) {
		int fd = getday(day, current);
		if (fd < 0) {
			cout << "error" << endl;
		}
		else {
			length += 0.1 * fd;
			weight += 0.2 * fd;
			cout << name << " after " << fd << fixed << setprecision(2) << " day: length=" << length << ",weight=" << weight <<
				endl;
		}

	}
	Cat(string n, float l, float w, CDate c) : Pet(n, l, w, c) {
	}
};

class Dog : public Pet {
public:
	virtual void display(CDate day) {
		int fd = getday(day, current);
		if (fd < 0) {
			cout << "error" << endl;
		}
		else {
			length += 0.2 * fd;
			weight += 0.1 * fd;
			cout << name << " after " << fd << fixed << setprecision(2) << " day: length=" << length << ",weight=" << weight <<
				endl;
		}

	}
	Dog(string n, float l, float w, CDate c) : Pet(n, l, w, c) {
	}
};

int getday(CDate& a, CDate& b) {
	if (a.y < b.y) {
		return -1;
	}
	if (a.y == b.y && a.m < b.m) {
		return -1;
	}
	if (a.y == b.y && a.m == b.m && a.d < b.d) {
		return -1;
	}
	int ans = 0;
	int i, year[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (a.y % 400 == 0 || a.y % 4 == 0 && a.y % 100 != 0) {
		year[1] = 28;
	}
	else {
		year[1] = 29;
	}
	for (i = 0; i < a.m - 1; i++) {
		ans = ans + year[i];
	}
	ans += a.d;
	if (a.y == b.y) {
		for (i = 0; i < b.m - 1; i++) {
			ans -= year[i];
		}
		ans -= b.d;
	}
	else {
		for (i = b.y + 1; i < a.y; i++) {
			if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) {
				ans += 366;
			}
			else {
				ans += 365;
			}
		}
		for (i = b.m; i < 12; i++) {
			ans += year[i];
		}
		ans = ans + year[b.m - 1] - b.d;
	}
	return ans;
}

int main() {
	int t, k, l, w, y, m, d;
	string name;
	cin >> t;
	Pet* pt;
	cin >> y >> m >> d;
	CDate c(y, m, d);
	while (t--) {
		cin >> k >> name >> l >> w >> y >> m >> d;
		CDate n(y, m, d);
		if (k == 1) {
			pt = new Cat(name, l, w, c);
			pt->display(n);
		}
		else {
			pt = new Dog(name, l, w, c);
			pt->display(n);
		}
	}
}