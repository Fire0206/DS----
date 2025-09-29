#include<iostream>
#include<iomanip>
using namespace std;
class CPoint {
protected:
	int x, y;
public:
	CPoint(int x1,int y1) {
		x = x1;
		y = y1;
	}
};

class CCircle :public CPoint {
protected:
	int r;
public:
	CCircle(int x1,int y1,int r1) :CPoint(x1, y1) {
		r = r1;
		
	}
	void Area() {
		cout << "Circle:(" << x << "," << y << ")," << r << endl;
		cout << "Area:" << fixed << setprecision(2) << 3.14 * r * r << endl;
	}
};

class CCylinder :public CCircle {
protected:
	int h;
public:
	CCylinder(int x1, int y1, int r1, int h1) :CCircle(x1, y1, r1) {
		h = h1;
		
	}
	void volume() {
		cout << "Cylinder:(" << x << "," << y << ")," << r << "," << h << endl;
		cout << "Volume:" << fixed << setprecision(2) << 3.14 * r * r * h << endl;
	}
};

int main() {
	int x, y, r, h;
	cin >> x >> y>>r;
	CCircle circle(x, y, r);
	circle.Area();
	cin >> x >> y >> r >> h;
	CCylinder cylinder(x, y, r, h);
	cylinder.volume();
	return 0;
}