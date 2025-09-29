#include <iostream>
using namespace std;
class Bulk {
private:
    double length;
    double width;
    double height;
    double volume;
    double areas;

public:
    void inputData() {
        cin >> length >> width >> height;
    }

    void calculate() {
        volume = length * width * height;
        areas = 2 * (length * width + length * height + width * height);
    }

    void output() {
        cout << volume << endl << areas ;
    }
};

int main() {
    Bulk b;
    b.inputData();
    b.calculate();
    b.output();
    return 0;
}    
