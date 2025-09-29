#include <iostream>
using namespace std;

template <int BASE>
class Value {
private:
    int high;  
    int mid;  
    int low;  
public:
    Value(int h = 0, int m = 0, int l = 0) : high(h), mid(m), low(l) {}

    Value operator+(const Value& other) const {
        int newLow = low + other.low;
        int carryToMid = newLow / BASE;
        newLow %= BASE;
        int newMid = mid + other.mid + carryToMid;
        int carryToHigh = newMid / BASE;
        newMid %= BASE;

        int newHigh = high + other.high + carryToHigh;

        return Value(newHigh, newMid, newLow);
    }

    friend ostream& operator<<(ostream& os, const Value& v) {
        os << v.high << " " << v.mid << " " << v.low;
        return os;
    }
};
template <int BASE>
Value<BASE> add(const Value<BASE>& a, const Value<BASE>& b, int) {
    return a + b;
}

int main() {
    using Clock = Value<60>;
    using RMB = Value<10>;

    int h1, m1, s1, h2, m2, s2;
    int y1, j1, f1, y2, j2, f2;

    cin >> h1 >> m1 >> s1;
    cin >> h2 >> m2 >> s2;
    cin >> y1 >> j1 >> f1;
    cin >> y2 >> j2 >> f2;

    Clock c1(h1, m1, s1), c2(h2, m2, s2);
    Clock c = add(c1, c2, 60);

    RMB r1(y1, j1, f1), r2(y2, j2, f2);
    RMB r = add(r1, r2, 10);

    cout << c << endl;
    cout << r << endl;

    return 0;
}