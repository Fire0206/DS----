#include <iostream>
using namespace std;

// 复数类
class Complex
{
    int real, image;   // 实部、虚部

public:
    Complex(int r, int i) : real(r), image(i) {}   // 构造函数
    void display()
    {
        if (real) {
            cout << real;
            if (image > 0)
                cout << "+";
        }
        if (image) {
            if (image != -1 && image != 1)
                cout << image;
            if (image == -1)
                cout << "-";
            cout << "i";
        }
        if (real == 0 && image == 0)
            cout << 0;
        cout << endl;
    }
    Complex operator+=(Complex& rhs);// 重载+=
};

// 补齐重载运算符实现
/********** Write your code here! **********/
Complex Complex::operator+=(Complex& rhs) {
    real += rhs.real;
    image += rhs.image;
    return *this;
}



/*******************************************/
// 主函数
int main()
{
    int real1, image1, real2, image2;  // 两个复数的实部、虚部
    cin >> real1 >> image1;
    cin >> real2 >> image2;
    // 定义两个复数对象c1,c2，输出计算结果。
    Complex c1(real1, image1), c2(real2, image2);
    c1.display();
    c2.display();
    cout << endl;
    c1 += c2;
    c1.display();
    c2.display();
    return 0;
}