#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
    
    void setYear(int y) { year = y; }
    void setMonth(int m) { month = m; }
    void setDay(int d) { day = d; }
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
};

class PID {
private:
    int type;
    string number;
    Date birthDate;
    
    string upgradeNumber() const {
        if (number.length() == 18) {
            return number;
        }
        
        // Step 1: 扩展年份
        string newNumber = number.substr(0, 6);
        newNumber += to_string(birthDate.getYear());
        newNumber += number.substr(6, 9);
        
        // Step 2: 计算校验位
        int sum = 0;
        for (char c : newNumber) {
            sum += c - '0';
        }
        int lastDigit = sum % 10;
        char checkDigit = (lastDigit == 0) ? 'X' : (lastDigit + '0');
        
        newNumber += checkDigit;
        return newNumber;
    }
    
public:
    PID(int t, const string& num, int y, int m, int d) : type(t), number(num), birthDate(y, m, d) {}
    
    // 拷贝构造函数
    PID(const PID& other) : birthDate(other.birthDate) {
        type = 2; // 升级为二代身份证
        number = other.upgradeNumber();
        birthDate = other.birthDate;
    }
    
    void print() const {
        cout << "type=" << type << endl;
        cout << "number=" << number << endl;
        cout << "birth=" << birthDate.getYear() << "." 
             << birthDate.getMonth() << "." 
             << birthDate.getDay() << endl;
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int type, year, month, day;
        string number;
        cin >> type >> number >> year >> month >> day;
        
        PID original(type, number, year, month, day);
        PID upgraded(original); // 使用拷贝构造函数升级
        upgraded.print();
    }
    
    return 0;
}
