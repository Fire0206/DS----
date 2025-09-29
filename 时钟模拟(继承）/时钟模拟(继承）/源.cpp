#include<iostream>
using namespace std;

class Count {
protected:
    int value;
public:
    Count() {}
    Count(int n) : value(n) {}
    int getV() {
        return value;
    }
    void increment() {
        value += 1;
    }
};

class Circle : public Count {
private:
    int min_value, max_value;
public:
    Circle() {}
    Circle(int a, int n, int m) : Count(a), min_value(n), max_value(m) {}
    void increment() {
        value += 1;
        if (value >= max_value) {
            value = min_value;
        }
    }
    void decrement(int m) {
        value -= m;
        if (value < min_value) {
            value = max_value - (min_value - value);
        }
    }
};

class Clock {
private:
    Circle hour;
    Circle minute;
    Circle second;
public:
    Clock(Circle hour1, Circle minute1, Circle second1) {
        hour = hour1;
        minute = minute1;
        second = second1;
    }
    void time(int s) {
        int s1 = s / 3600;
        int s2 = (s % 3600) / 60;
        int s3 = s % 60;

        for (int i = 0; i < s1; i++) {
            hour.increment();
        }
        for (int i = 0; i < s2; i++) {
            minute.increment();
            if (minute.getV() == 0) {
                hour.increment();
            }
        }
        for (int i = 0; i < s3; i++) {
            second.increment();
            if (second.getV() == 0) {
                minute.increment();
                if (minute.getV() == 0) {
                    hour.increment();
                }
            }
        }

        cout << hour.getV() << ":" << minute.getV() << ":" << second.getV() << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h, m, s;
        cin >> h >> m >> s;
        Circle hour(h, 0, 24);
        Circle minute(m, 0, 60);
        Circle second(s, 0, 60);
        Clock clo(hour, minute, second);
        int c;
        cin >> c;
        clo.time(c);
    }
    return 0;
}