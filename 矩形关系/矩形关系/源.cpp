#include<iostream>
using namespace std;
class CRectangle;
class CPoint {
private:
	int x;
	int y;
public:
	CPoint(int x1, int y1) :x(x1), y(y1) {}
	int getX(){
		return x;
	}
	int getY() {
		return y;
	}
	bool operator>(const CRectangle& tan);
};
class CRectangle {
private:
	friend bool CPoint::operator>(const CRectangle& tan);
	CPoint leftPoint;
	CPoint rightPoint;
public:
	CRectangle(int x1,int y1,int x2,int y2):
		leftPoint(x1,y1),rightPoint(x2,y2){}
	int getArea() {
		return ((rightPoint.getX() - leftPoint.getX()) * (leftPoint.getY() - rightPoint.getY()));
	}
	int getPerimeter() {
		return 2*((rightPoint.getX() - leftPoint.getX()) + (leftPoint.getY() - rightPoint.getY()));
	}
	bool isSquare() {
		return ((rightPoint.getX() - leftPoint.getX()) == (leftPoint.getY() - rightPoint.getY()));
	}
	void move(int x1, int y1) {

	}
	bool contains(CPoint point) {
		if (point.getX() >= leftPoint.getX() && point.getX() <= rightPoint.getX() && point.getY() >= rightPoint.getY() && point.getY() <= leftPoint.getY()) {
			return true;
		}
		return false;
	}
	bool intersect(CRectangle rect) {
		if (contains(rect.leftPoint) && contains(rect.leftPoint)) {
			return true;
		}
		return false;
	}
	bool operator==( CRectangle& other) {
		if (leftPoint.getX() == other.leftPoint.getX() && leftPoint.getY() == other.leftPoint.getY()) {
			return true;
		}
		return false;
	}
	bool operator>(CRectangle & other) {
		if (intersect(other)) {
			return true;
		}
		return false;
	}
	bool operator*(CRectangle& rect) {
		if (rightPoint.getX() < rect.leftPoint.getX() || rect.rightPoint.getX() < leftPoint.getX())
			return false;
		if (leftPoint.getY() < rect.rightPoint.getY() || rect.leftPoint.getY() < rightPoint.getY())
			return false;
		return true;
	}
	friend ostream& operator<<(ostream& cout, CRectangle& rect) {
		cout << rect.leftPoint.getX() << " " << rect.leftPoint.getY() << " " << rect.rightPoint.getX() <<" " << rect.rightPoint.getY() << " ";
		return cout;
	}
};

int main() {
	int t,x1,x2,y1,y2;
	cin >> t;
	while (t--) {
		cin >> x1 >> y1 >> x2 >> y2;
		CRectangle rect1(x1, y1, x2, y2);
		cin >> x1 >> y1 >> x2 >> y2;
		CRectangle rect2(x1, y1, x2, y2);
		cout << "矩形1:" << rect1 << rect1.getArea() << endl;
		cout << "矩形2:" << rect2 << rect2.getArea() << endl;
		if (rect1 == rect2) {
			cout << "矩形1和矩形2相等" << endl;
		}
		else if(rect2>rect1){
			cout << "矩形2包含矩形1" << endl;
		}
		else if (rect1 > rect2) {
			cout << "矩形1包含矩形2" << endl;
		}
		else if (rect1 * rect2) {
			cout << "矩形1和矩形2相交" << endl;
		}
		else {
			cout << "矩形1和矩形2不相交" << endl;
		}
		cout << endl;
	}
	return 0;
}