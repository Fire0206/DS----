#include<iostream>
using namespace std;

class CN; //提前声明
class EN; //提前声明

class Weight { //抽象类
protected:
    string kind; //计重类型
    int gram;    //克
public:
    Weight(string tk = "no name", int tg = 0) {
        kind = tk;
        gram = tg;
    }
    virtual void Print(ostream& out) = 0; //输出不同类型的计重信息
};

class CN : public Weight { //中国计重
private:
    int jin, liang, qian;
public:
    CN(int j, int l, int q, int tg, string tk) : Weight(tk, tg), jin(j), liang(l), qian(q) {}

    void Convert(int g) {
        jin = g / 500;
        liang = (g % 500) / 50;
        qian = (g % 50) / 5;
        gram = g % 5;
    }

    void Print(ostream& out) override {
        out << kind << ":" << jin << "斤" << liang << "两" << qian << "钱" << gram << "克" << endl;
    }

    // ? 加上重载赋值运算符
    CN& operator=(const EN& en);
};

class EN : public Weight { //英国计重
private:
    int pound, ounce, dram;
public:
    EN(int j, int l, int q, int tg, string tk) : Weight(tk, tg), pound(j), ounce(l), dram(q) {}

    void Convert(int g) {
        pound = g / 512;
        ounce = (g % 512) / 32;
        dram = (g % 32) / 2;
        gram = g % 2;
    }

    void Print(ostream& out) override {
        out << kind << ":" << pound << "磅" << ounce << "盎司" << dram << "打兰" << gram << "克" << endl;
    }
    friend CN& CN::operator=(const EN& en);
    friend ostream& operator<<(ostream& os, Weight& w);
};

// ? CN类中实现：把EN转为CN
CN& CN::operator=(const EN& en) {
    int g = en.pound * 512 + en.ounce * 32 + en.dram * 2 + en.gram;
    Convert(g);
    kind = "中国计重";
    return *this;
}

// ? 全局函数：重载输出运算符
ostream& operator<<(ostream& os, Weight& w) {
    w.Print(os);
    return os;
}

int main() {
    int tw;

    CN cn(0, 0, 0, 0, "中国计重");
    cin >> tw;
    cn.Convert(tw);
    cout << cn;

    EN en(0, 0, 0, 0, "英国计重");
    cin >> tw;
    en.Convert(tw);
    cout << en;

    cn = en; //调用CN::operator=(const EN&)
    cout << cn;

    return 0;
}
