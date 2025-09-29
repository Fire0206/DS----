#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class PID; 
class Date {
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    void print() const {
        cout << year << "."
            << setw(2) << setfill('0') << month<<"."
            << setw(2) << setfill('0') << day << endl;
    }
    friend class PID; 
};

class PID {
private:
    int type;
    string num;
    Date date;

public:
    PID(int t, string n, int y, int m, int d) : type(t), num(n), date(y, m, d) {}

    PID(const PID& p) : type(2), num(p.num), date(p.date) {
        if (p.type == 1) {
            string yearStr = to_string(p.date.year);
            num.insert(6, yearStr.substr(0, 2));
            while (num.length() < 18) {
                num += "0";
            }
            int n = 0;
            for (int i = 0; i < 17; ++i) {
                if (isdigit(num[i])) {
                    n += num[i] - '0';
                }
            }
            int sum = n % 10;
            num[17] = (sum == 0) ? 'X' : ('0' + sum);  
        }
    }
    void print() const {
        cout << "type=" << type << " birth=";
        date.print();
        cout << "ID=" << num << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int type, year, month, day;
        string num;
        cin >> type >> num >> year >> month >> day;

        PID p1(type, num, year, month, day);
        PID p2 = p1; 
        p2.print();
    }

    return 0;
}
