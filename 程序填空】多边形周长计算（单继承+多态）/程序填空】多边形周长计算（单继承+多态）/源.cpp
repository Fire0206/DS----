#include<iostream>
using namespace std;

class polygon {
protected:
    int number;
public:
    int side_length[100];

    polygon() : number(0) {}
    polygon(int nu, int si[]) : number(nu) {
        for (int i = 0; i < nu; i++) {
            side_length[i] = si[i];
        }
    }
    virtual int perimeter() {
        int sum = 0;
        for (int i = 0; i < number; i++) {
            sum += side_length[i];
        }
        return sum;
    }
    void display() {
        cout << number << " " << perimeter() << endl;
    }
};

class rectangle : public polygon {
protected:
    int height, width;
public:
    rectangle(int he, int wi) : polygon(4, new int[4] {he, wi, he, wi}), height(he), width(wi) {}
    int perimeter() override {
        return (height + width) * 2;
    }
};

class equal_polygon : public polygon {
protected:
    int side_len;
public:
    equal_polygon(int nu, int si) : polygon(nu, nullptr), side_len(si) {
        for (int i = 0; i < nu; i++) {
            side_length[i] = si;
        }
        number = nu;
    }
    int perimeter() override {
        return number * side_len;
    }
};

int main()
{
    int t;
    string type;
    int side_length[100], number, side_len, width, height;
    polygon* p = nullptr;

    cin >> t;
    while (t--)
    {
        cin >> type;
        if (type == "0")    // 多边形
        {
            number = 0;
            while (cin >> side_length[number])
            {
                if (side_length[number] == -1)
                    break;
                number++;
            }
            cin.clear(); // 重置 cin 状态
            cin.ignore(10000, '\n'); // 清除输入缓冲区
            p = new polygon(number, side_length);
        }
        else if (type == "1")   // 矩形
        {
            cin >> height >> width;
            p = new rectangle(height, width);
        }
        else if (type == "2")   // 等边多边形
        {
            cin >> number >> side_len;
            p = new equal_polygon(number, side_len);
        }
        p->display();
        delete p;
    }
    return 0;
}



