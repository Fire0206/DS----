#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    // 构造函数直接读取输入
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    // 析构函数
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    // 拷贝构造函数
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new int* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // 赋值运算符重载
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;

            rows = other.rows;
            cols = other.cols;
            data = new int* [rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    // 加法运算符重载
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // 减法运算符重载
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // 输出矩阵的成员函数
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        Matrix a(r, c);
        Matrix b(r, c);

        // 输出第一组结果：a+b 和 a-b
        cout << "Add:" << endl;
        (a + b).print();
        cout << "Minus:" << endl;
        (a - b).print();
        cout << "-----------------" << endl;

        // 输出第二组结果：b+a 和 b-a（注意减法顺序交换）
        cout << "Add:" << endl;
        (b + a).print();
        cout << "Minus:" << endl;
        (b - a).print();
        cout << "-----------------" << endl;
    }
    return 0;
}