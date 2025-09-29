#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string maskNumber(const string& number) {
    if (number.length() < 8) {
        return number;
    }
    string masked = number.substr(0, 4);
    masked.append(8, '*');
    masked += number.substr(number.length() - 4);
    return masked;
}
struct Card {
    string Name;
    string Terminal;
    string Operator;
    string CardIssuers;
    string Validity;
    string CardNumber;
    string Traded;
    double Costs;
};

int main() {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        Card a;
        cin >> a.Name >> a.Terminal >> a.Operator >> a.CardIssuers >> a.Validity >> a.CardNumber >> a.Traded >> a.Costs;
        string maskedNumber = maskNumber(a.CardNumber);
        cout << "Name:" <<" "<< a.Name << endl;
        cout << "Terminal:" <<" "<< a.Terminal << " ";
        cout << "operator:" <<" "<< a.Operator << endl;
        cout << "Card Issuers:" <<" "<< a.CardIssuers << " ";
        cout << "Validity:" <<" "<< a.Validity << endl;
        cout << "CardNumber:" <<" "<< maskedNumber << endl;
        cout << "Traded:" <<" "<< a.Traded << endl;
        cout << "Costs: $";
        cout << fixed << setprecision(2) << a.Costs;
        if (j != t - 1) {
            cout << endl << endl;
        }
    }
    return 0;
}
