#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
class Point {
	friend double Distance(Point& a, Point& b);
private:
	double x, y;

public:
	Point(double xx, double yy) {
		x = xx;
		y = yy;
	}
};

double Distance(Point& a, Point& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		double x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point p1(x1, y1);
		Point p2(x2, y2);
		cout << fixed<<setprecision(0)<<Distance(p1, p2) << endl;
	}
	return 0;
}