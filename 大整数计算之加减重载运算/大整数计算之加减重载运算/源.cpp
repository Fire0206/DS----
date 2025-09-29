#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class CBigInteger {
private:
    string digits;
    bool isNegative;

public:
    CBigInteger() : digits("0"), isNegative(false) {}

    CBigInteger(const string& num) {
        if (num.empty()) {
            digits = "0";
            isNegative = false;
            return;
        }
        if (num[0] == '-') {
            isNegative = true;
            digits = num.substr(1);
            if (digits.empty()) digits = "0";
        }
        else {
            isNegative = false;
            digits = num;
        }
        // 去除前导零
        while (digits.length() > 1 && digits[0] == '0')
            digits = digits.substr(1);
        if (digits == "0") isNegative = false;
    }

    bool absGreater(const CBigInteger& other) const {
        if (digits.length() != other.digits.length())
            return digits.length() > other.digits.length();
        return digits > other.digits;
    }

    CBigInteger operator+(const CBigInteger& other) const {
        if (isNegative == other.isNegative) {
            CBigInteger result;
            result.isNegative = isNegative;
            string res;
            int i = digits.length() - 1, j = other.digits.length() - 1, carry = 0;
            while (i >= 0 || j >= 0 || carry) {
                int sum = carry;
                if (i >= 0) sum += digits[i--] - '0';
                if (j >= 0) sum += other.digits[j--] - '0';
                res.push_back(sum % 10 + '0');
                carry = sum / 10;
            }
            reverse(res.begin(), res.end());
            result.digits = res;
            return result;
        }
        else {
            if (absGreater(other)) {
                CBigInteger result;
                result.isNegative = isNegative;
                string res;
                int i = digits.length() - 1, j = other.digits.length() - 1, borrow = 0;
                while (i >= 0) {
                    int diff = (digits[i--] - '0') - borrow;
                    if (j >= 0) diff -= other.digits[j--] - '0';
                    if (diff < 0) {
                        diff += 10;
                        borrow = 1;
                    }
                    else {
                        borrow = 0;
                    }
                    res.push_back(diff + '0');
                }
                reverse(res.begin(), res.end());
                // 去除前导零
                while (res.length() > 1 && res[0] == '0')
                    res = res.substr(1);
                result.digits = res;
                return result;
            }
            else {
                CBigInteger result;
                result.isNegative = other.isNegative;
                string res;
                int i = other.digits.length() - 1, j = digits.length() - 1, borrow = 0;
                while (i >= 0) {
                    int diff = (other.digits[i--] - '0') - borrow;
                    if (j >= 0) diff -= digits[j--] - '0';
                    if (diff < 0) {
                        diff += 10;
                        borrow = 1;
                    }
                    else {
                        borrow = 0;
                    }
                    res.push_back(diff + '0');
                }
                reverse(res.begin(), res.end());
                // 去除前导零
                while (res.length() > 1 && res[0] == '0')
                    res = res.substr(1);
                result.digits = res;
                return result;
            }
        }
    }

    CBigInteger operator-(const CBigInteger& other) const {
        CBigInteger temp(other);
        temp.isNegative = !temp.isNegative;
        return (*this + temp);
    }

    friend ostream& operator<<(ostream& os, const CBigInteger& num) {
        if (num.isNegative && num.digits != "0")
            os << '(' << '-' << num.digits << ')';
        else
            os << num.digits;
        return os;
    }
};

string formatOutput(const string& num) {
    string formatted = num;
    // 去除前导零
    while (formatted.length() > 1 && formatted[0] == '0')
        formatted = formatted.substr(1);
    // 处理负数
    if (formatted[0] == '-') {
        if (formatted == "-0") return "0";
        return "(" + formatted + ")";
    }
    return formatted;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        string num1, op, num2;
        cin >> num1 >> op >> num2;
        CBigInteger a(num1);
        CBigInteger b(num2);
        CBigInteger result;
        if (op == "+") {
            result = a + b;
        }
        else {
            result = a - b;
        }
        cout << formatOutput(num1) << " " << op << " " << formatOutput(num2) << " = " << result << endl;
    }
    return 0;
}