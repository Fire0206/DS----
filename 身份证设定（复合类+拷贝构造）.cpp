#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    int getYear() const {
        return year;
    }
    int getMonth() const {
        return month;
    }
    int getDay() const {
        return day;
    }
};

string intToString(int num) {
    string result = "";
    do {
        result = static_cast<char>(num % 10 + '0') + result;
        num /= 10;
    } while (num > 0);
    return result;
}
class PID {
private:
    int type;
    string number;
    Date birthDate;

public
    PID(int t, string num, const Date& date) : type(t), number(num), birthDate(date) {}

    PID(const PID& other) : birthDate(other.birthDate) {
        type = 2;
        if (other.number.length() == 15) {
            number = other.number;
            int year = birthDate.getYear();
            string yearStr = intToString(year);
            number.insert(6, yearStr.substr(0, 2));

            int sum = 0;
            for (int i = 0; i < 17; ++i) {
                sum += number[i] - '0';
            }
            int lastDigit = sum % 10;
            if (lastDigit == 0) {
                number += 'X';
            } else {
                number += static_cast<char>(lastDigit + '0');
            }
        } else {
            number = other.number;
        }
    }
    void print() const {
        cout << "type=" << type << " birth=" << birthDate.getYear() << ".";
        cout.width(2);
        cout.fill('0');
        cout << birthDate.getMonth() << ".";
        cout.width(2);
        cout.fill('0');
        cout << birthDate.getDay() << endl;
        cout << "ID=" << number << endl;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int type, year, month, day;
        string number;
        cin >> type >> number >> year >> month >> day;

        Date date(year, month, day);
        PID original(type, number, date);
        PID upgraded(original);

        upgraded.print();
    }

    return 0;
}
    
