#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

struct Num {
    int up;
    int down;
};

int getGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Num simplify(Num a) {
    int gcdnum = getGCD(abs(a.up), abs(a.down));
    a.up /= gcdnum;
    a.down /= gcdnum;
    if (a.down < 0) {
        a.down = -a.down;
        a.up = -a.up;
    }
    return a;
}

Num addFS(Num a, Num b) {
    Num result;
    result.up = a.up * b.down + a.down * b.up;
    result.down = a.down * b.down;
    return simplify(result);
}

Num subFS(Num a, Num b) {
    Num result;
    result.up = a.up * b.down - a.down * b.up;
    result.down = a.down * b.down;
    return simplify(result);
}

Num mulFS(Num a, Num b) {
    Num result;
    result.up = a.up * b.up;
    result.down = a.down * b.down;
    return simplify(result);
}

Num divFS(Num a, Num b) {
    if (b.up == 0) {
        return {0, 1};
    }
    Num result;
    result.up = a.up * b.down;
    result.down = a.down * b.up;
    return simplify(result);
}

void printFS(Num a) {
    if (a.down == 1) {
        cout << a.up << endl;
    } else {
        cout << a.up << "/" << a.down << endl;
    }
}

Num fraction(const string& s) {
    Num num;
    istringstream iss(s);
    char slash;
    iss >> num.up >> slash >> num.down;
    return num;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    for (int i = 0; i < t; i++) {
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);
        Num a = fraction(line1);
        Num b = fraction(line2);
        printFS(addFS(a, b));
        printFS(subFS(a, b));
        printFS(mulFS(a, b));
        printFS(divFS(a, b));
        if (i != t - 1) {
            cout << endl;
        }
    }
    return 0;
}
