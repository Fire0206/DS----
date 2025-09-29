#include <iostream>
#include <string>
using namespace std;

class Figure {
private:
    int size;

public:
    Figure(int s = 0) : size(s) {}

    friend istream& operator>>(istream& is, Figure& fig) {
        is >> fig.size;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Figure& fig) {
        for (int i = 0; i < fig.size; ++i) {
            for (int j = 0; j < fig.size; ++j) {
                os << '*';
            }
            os << endl;
        }
        return os;
    }

    Figure& operator++() {
        ++size;
        return *this;
    }
    Figure operator++(int) {
        Figure temp = *this;
        ++(*this);
        return temp;
    }
    Figure& operator--() {
        --size;
        return *this;
    }

    Figure operator--(int) {
        Figure temp = *this;
        --(*this);
        return temp;
    }
};

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        Figure fig;
        int n;
        cin >> fig >> n;

        for (int j = 0; j < n; ++j) {
            string op;
            cin >> op;

            if (op == "ADD") {
                cout << ++fig;
            }
            else if (op == "add") {
                cout << fig++;
            }
            else if (op == "MINUS") {
                cout << --fig;
            }
            else if (op == "minus") {
                cout << fig--;
            }

                cout << endl;
        }

            cout << "----------" << endl;
    }

    return 0;
}