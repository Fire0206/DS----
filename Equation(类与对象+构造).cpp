#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Equation {
private:
    double a, b, c;
public:
    Equation() {
        a = 1;
        b = 1;
        c = 0;
    }
    Equation(double a1, double b1, double c1) {
        a = a1;
        b = b1;
        c = c1;
    }
    void setABC(double a1, double b1, double c1) {
        a = a1;
        b = b1;
        c = c1;
    }
    void getRoot() {
        double delta = b * b - 4 * a * c;
        cout << fixed << setprecision(2);
        if (delta > 0) {
            double root1 = (-b + sqrt(delta)) / (2.0 * a);
            double root2 = (-b - sqrt(delta)) / (2.0 * a);
            cout << "x1=" << root1 << " "
                 << "x2=" << root2 << endl;
        } else if (delta == 0) {
            double root = -b / (2.0 * a);
            cout << "x1=x2=" << root << endl;
        } else {
            double realPart = -b / (2.0 * a);
            double imagPart = sqrt(-delta) / (2.0 * a);
            imagPart=fabs(imagPart);
            cout << "x1=" << realPart << "+" << imagPart << "i "
                 << "x2=" << realPart << "-" << imagPart << "i" << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    double a, b, c;
    while (t--) {
        cin >> a >> b >> c;
        Equation eq(a, b, c);
        eq.getRoot();
    }
    return 0;
}    
