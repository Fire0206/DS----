#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 定义一个表示四进制数的类
class Quaternary {
private:
    int value; // 存储四进制数对应的十进制整数值

public:
    // 构造函数，接受一个字符串表示的四进制数，并将其转换为十进制整数
    Quaternary(const std::string& quaternaryStr) {
        value = 0;
        int length = quaternaryStr.length();
        for (int i = 0; i < length; ++i) {
            // 将字符串中的每一位字符转换为数字，并计算其在十进制中的权重
            value += (quaternaryStr[length - 1 - i] - '0') * static_cast<int>(pow(4, i));
        }
    }

    // 构造函数，直接接受一个十进制整数
    Quaternary(int val) : value(val) {}

    // 重载加法运算符，允许两个 Quaternary 对象相加
    Quaternary operator+(const Quaternary& other) const {
        return Quaternary(this->value + other.value);
    }

    // 方法，将内部存储的十进制整数转换回四进制字符串
    std::string toQuaternary() const {
        if (value == 0) return "0"; // 如果值为0，直接返回"0"
        std::string result = "";
        int temp = value;
        while (temp > 0) {
            // 计算当前最低位的四进制数，并添加到结果字符串前面
            result = std::to_string(temp % 4) + result;
            temp /= 4; // 去掉最低位
        }
        return result;
    }
};

int main() {
    int n;
    std::cin >> n; // 读取输入的四进制数的数量
    Quaternary total(0); // 创建一个初始值为0的 Quaternary 对象

    for (int i = 0; i < n; ++i) {
        std::string quaternaryNumber;
        std::cin >> quaternaryNumber; // 读取每个四进制数
        Quaternary current(quaternaryNumber); // 将读取的四进制数转换为 Quaternary 对象
        total = total + current; // 累加到总和中
    }

    std::cout << total.toQuaternary() << std::endl; // 输出最终的累加和（四进制形式）
    return 0;
}







