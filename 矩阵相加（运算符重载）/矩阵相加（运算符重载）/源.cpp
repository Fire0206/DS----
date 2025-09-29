#include<iostream>
using namespace std;
class Matrix {
    int m, n;
    int** data;
public:
    Matrix(int rows, int cols) : m(rows), n(cols) {
        data = new int* [m];
        for (int i = 0; i < m; i++) {
            data[i] = new int[n];
        }
    }

    void input() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> data[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < m; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    Matrix(const Matrix& other) : m(other.m), n(other.n) {
        data = new int* [m];
        for (int i = 0; i < m; i++) {
            data[i] = new int[n];
            for (int j = 0; j < n; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix& operator= (const Matrix& other) {
        if (this != &other) {
            for (int i = 0; i < m; i++) {
                delete[] data[i];
            }
            delete[] data;

            m = other.m;
            n = other.n;
            data = new int* [m];
            for (int i = 0; i < m; i++) {
                data[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;  
    }

    void print() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << data[i][j];
                if (j != (n - 1)) {
                    cout << " ";
                }
                else {
                    cout << endl;
                }
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    int m, n;
    while (t--) {
        cin >> m >> n;
        Matrix m1(m,n);
        Matrix m2(m,n);
        m1.input();
        m2.input();
        Matrix m3 = m1 + m2;
        m3.print();
    }
    return 0;
}