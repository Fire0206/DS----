#include <iostream>
#include <iomanip>

const double PI = 3.14159265358979323846;

using namespace std;

class Shape {
protected:
    string name;
    double x;
    double y;
public:
    Shape() {}
    virtual ~Shape() {}
    virtual string getName() const { return name; }
    virtual double getX() const { return x; }
    virtual double getY() const { return y; }
    virtual double getArea() const { return 0.0; }
    virtual double getVolume() const { return 0.0; }
    virtual void shapeName(const string& n) { name = n; }
};
class Point : public Shape {
public:
    Point(double xVal, double yVal) {
        x = xVal;
        y = yVal;
        shapeName("Point");
    }
};

class Circle : public Point {
private:
    double r;
public:
    Circle(double xVal, double yVal, double rVal) : Point(xVal, yVal) {
        r = rVal;
        shapeName("Circle");
    }
    double getArea() const override {
        return PI * r * r;
    }
    double getRadius() const {
        return r;
    }
};
class Cylinder : public Circle {
private:
    double h;
public:
    Cylinder(double xVal, double yVal, double rVal, double hVal) : Circle(xVal, yVal, rVal) {
        h = hVal;
        shapeName("Cylinder");
    }
    double getArea() const override {
        double r = getRadius();
        return 2 * PI * r * (r + h);
    }
    double getVolume() const override {
        double r = getRadius();
        return PI * r * r * h;
    }
};

void Print(const Shape* s) {
    cout << s->getName() << "--(" << fixed << setprecision(1) << s->getX() << "," << s->getY() << ")"
        << "--" << static_cast<int>(s->getArea()) << "--" << static_cast<int>(s->getVolume()) << endl;
}

int main() {
    double x, y, r, h;
    cin >> x >> y;
    Point p(x, y);
    cin >> x >> y >> r;
    Circle c(x, y, r);
    cin >> x >> y >> r >> h;
    Cylinder cy(x, y, r, h);

    Print(&p);
    Print(&c);
    Print(&cy);

    return 0;
}