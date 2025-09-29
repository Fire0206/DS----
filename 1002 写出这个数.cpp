#include <iostream>
#include <string>
using namespace std;

string pinyin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    string n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n.length(); i++) {
        sum += n[i] - '0';
    }

    string result;
    if (sum == 0) {
        result = "0";
    } else {
        while (sum > 0) {
            result = static_cast<char>(sum % 10 + '0') + result;
            sum /= 10;
        }
    }

    for (int i = 0; i < result.length(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << pinyin[result[i] - '0'];
    }
    cout << endl;

    return 0;
}
