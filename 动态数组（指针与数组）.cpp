#include <iostream>
using namespace std;
double calculate(int* arr, int n) {
    int sum = 0;
    int* ptr = arr;
    for (int i = 0; i < n; ++i) {
        sum += *ptr;
        ptr++;
    }
    return static_cast<double>(sum) / n;
}
char max(char* arr, int n) {
    char maxChar = *arr;
    char* ptr = arr + 1;
    for (int i = 1; i < n; ++i) {
        if (*ptr > maxChar) {
            maxChar = *ptr;
        }
        ptr++;
    }
    return maxChar;
}
float min(float* arr, int n) {
    float minFloat = *arr;
    float* ptr = arr + 1;
    for (int i = 1; i < n; ++i) {
        if (*ptr < minFloat) {
            minFloat = *ptr;
        }
        ptr++;
    }
    return minFloat;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        char type;
        int n;
        cin >> type >> n;
        if (type == 'I') {
            int* intArr = new int[n];
            int* ptr = intArr;
            for (int i = 0; i < n; ++i) {
                cin >> *ptr;
                ptr++;
            }
            double average = calculate(intArr, n);
            cout << average << endl;
            delete[] intArr;
        } else if (type == 'C') {
            char* charArr = new char[n];
            char* ptr = charArr;
            for (int i = 0; i < n; ++i) {
                cin >> *ptr;
                ptr++;
            }
            char maxChar = max(charArr, n);
            cout << maxChar << endl;
            delete[] charArr;
        } else if (type == 'F') {
            float* floatArr = new float[n];
            float* ptr = floatArr;
            for (int i = 0; i < n; ++i) {
                cin >> *ptr;
                ptr++;
            }
            float minFloat = min(floatArr, n);
            cout << minFloat << endl;
            delete[] floatArr;
        }
    }
    return 0;
}
