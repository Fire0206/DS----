#include <iostream>
using namespace std;

// 计算整数数组的平均值
double calculateAverage(int *arr, int n) {
    double sum = 0;
    int *ptr = arr;
    for (int i = 0; i < n; i++) {
        sum += *ptr;
        ptr++;
    }
    return sum / static_cast<double>(n);
}

// 找出字符数组中的最大字符
char maxChar(char* arr, int n) {
    char max = *arr;
    char* ptr = arr;  // 从数组第一个元素开始
    for (int i = 0; i < n; i++) {
        if (*ptr > max) {
            max = *ptr;
        }
        ptr++;
    }
    return max;
}

// 找出浮点数数组中的最小值
float minNum(float* arr, int n) {
    float min = *arr;
    float* ptr = arr;  // 从数组第一个元素开始
    for (int i = 0; i < n; i++) {
        if (*ptr < min) {
            min = *ptr;
        }
        ptr++;
    }
    return min;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        char type;
        int n;
        cin >> type >> n;

        // 输入验证
        if (n <= 0) {
            cerr << "Invalid array length. Please enter a positive integer." << endl;
            continue;
        }

        switch (type) {
            case 'I': {
                int *intArray = new int[n];
                int *intPtr = intArray;
                for (int i = 0; i < n; i++) {
                    cin >> *intPtr;
                    intPtr++;
                }
                double average = calculateAverage(intArray, n);
                cout << average << endl;
                delete[] intArray;
                break;
            }
            case 'C': {
                char *charArray = new char[n];
                char *charPtr = charArray;
                for (int i = 0; i < n; i++) {
                    cin >> *charPtr;
                    charPtr++;
                }
                char max = maxChar(charArray, n);
                cout << max << endl;
                delete[] charArray;
                break;
            }
            case 'F': {
                float* floatArray = new float[n];
                float* floatPtr = floatArray;
                for (int i = 0; i < n; i++) {
                    cin >> *floatPtr;
                    floatPtr++;
                }
                float min = minNum(floatArray, n);
                cout << min << endl;
                delete[] floatArray;
                break;
            }
            default:
                cerr << "Invalid array type. Please enter 'I', 'C', or 'F'." << endl;
                break;
        }
    }
    return 0;
}
