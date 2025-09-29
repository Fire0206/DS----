#include <iostream>
#include <string>
using namespace std;

template <class T>
string mergeSecrets(const T* dragonBlade, const T* heavenSword, int n) {
    string result;
    for (int i = 0; i < n; i++) {
        result += to_string(dragonBlade[i]);
    }
    for (int i = 0; i < n; i++) {
        result += to_string(heavenSword[i]);
    }
    return result;
}

template <>
string mergeSecrets<char>(const char* dragonBlade, const char* heavenSword, int n) {
    string result(dragonBlade, n);
    result.append(heavenSword, n);
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        char type;
        int n;
        cin >> type >> n;
        if (type == 'I') {
            int* dragonBlade = new int[n];
            int* heavenSword = new int[n];
            for (int i = 0; i < n; i++) cin >> heavenSword[i];
            for (int i = 0; i < n; i++) cin >> dragonBlade[i];
            cout << mergeSecrets(dragonBlade, heavenSword, n) << endl;
            delete[] dragonBlade;
            delete[] heavenSword;
        }
        else if (type == 'D') {
            double* dragonBlade = new double[n];
            double* heavenSword = new double[n];
            for (int i = 0; i < n; i++) cin >> heavenSword[i];
            for (int i = 0; i < n; i++) cin >> dragonBlade[i];
            cout << mergeSecrets(dragonBlade, heavenSword, n) << endl;
            delete[] dragonBlade;
            delete[] heavenSword;
        }
        else if (type == 'C') {
            char* dragonBlade = new char[n];
            char* heavenSword = new char[n];
            for (int i = 0; i < n; i++) cin >> heavenSword[i];
            for (int i = 0; i < n; i++) cin >> dragonBlade[i];
            cout << mergeSecrets(dragonBlade, heavenSword, n) << endl;
            delete[] dragonBlade;
            delete[] heavenSword;
        }
    }

    return 0;
}