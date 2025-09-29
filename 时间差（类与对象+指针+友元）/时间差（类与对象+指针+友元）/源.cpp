#include <iostream>
using namespace std;

class Time {
private:
    int h, m, s;
public:
    Time(int h1, int m1, int s1) : h(h1), m(m1), s(s1) {}
    friend int diff(Time* t1, Time* t2);
    int getH() {
        return h;
    }
    int getM() {
        return m;
    }
    int getS() {
        return s;
    }
};

int diff(Time* t1, Time* t2) {
    int d1 = t1->getS() + t1->getM() * 60 + t1->getH() * 3600;
    int d2 = t2->getS() + t2->getM() * 60 + t2->getH() * 3600;
    int dif = (d1 - d2);
    if (dif < 0) {
        dif = -dif;
    }
    return dif;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h1, h2, m1, m2, s1, s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        Time t1(h1, m1, s1);
        Time t2(h2, m2, s2);
        cout << h1 << "时" << m1 << "分" << s1 << "秒--" << h2 << "时" << m2 << "分" << s2 << "秒时间差为" << diff(&t1, &t2) << "秒" << endl;
    }
    return 0;
}