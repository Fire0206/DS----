#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Goods {
private:
    string id;
    string name;
    string color;
    string size;
    double price;
    int number;

public:
    // 构造函数
    Goods(string id, string name, string color, string size, double price, int number)
        : id(id), name(name), color(color), size(size), price(price), number(number) {
    }

    // 计算总价
    double totalPrice() const {
        return price * number;
    }

    // 输出商品信息
    void print() const {
        cout << id << " " << name << " " << color << " " << size << " " << fixed << setprecision(2) << price << " " << number << " " << totalPrice() << endl;
    }

    // 增加商品数量
    void add(int a) {
        number += a;
    }

    // 减少商品数量
    void del(int a) {
        if (number - a >= 1) {
            number -= a;
        }
    }

    // 获取商品编号
    string getID() const {
        return id;
    }

    // 获取商品数量
    int getNumber() const {
        return number;
    }
};

class Shoppingcar {
private:
    Goods* goods[100];
    int type;
    int amount;
    double sumPrice;

public:
    // 构造函数
    Shoppingcar() : type(0), amount(0), sumPrice(0) {
        for (int i = 0; i < 100; i++) {
            goods[i] = nullptr;
        }
    }

    // 析构函数
    ~Shoppingcar() {
        for (int i = 0; i < type; i++) {
            delete goods[i];
        }
    }

    // 添加商品
    void ADD(string id, string name, string color, string size, double price, int number) {
        for (int i = 0; i < type; i++) {
            if (goods[i]->getID() == id) {
                goods[i]->add(number);
                amount += number;
                sumPrice += price * number;
                return;
            }
        }
        goods[type] = new Goods(id, name, color, size, price, number);
        type++;
        amount += number;
        sumPrice += price * number;
    }

    // 删除商品
    void DELETE(string id) {
        for (int i = 0; i < type; i++) {
            if (goods[i]->getID() == id) {
                amount -= goods[i]->getNumber();
                sumPrice -= goods[i]->totalPrice();
                delete goods[i];
                for (int j = i; j < type - 1; j++) {
                    goods[j] = goods[j + 1];
                }
                goods[type - 1] = nullptr;
                type--;
                break;
            }
        }
    }

    // 增加商品数量
    void UP(string id) {
        for (int i = 0; i < type; i++) {
            if (goods[i]->getID() == id) {
                goods[i]->add(1);
                amount++;
                sumPrice += goods[i]->price;
                break;
            }
        }
    }

    // 减少商品数量
    void DOWN(string id) {
        for (int i = 0; i < type; i++) {
            if (goods[i]->getID() == id) {
                int oldNumber = goods[i]->getNumber();
                goods[i]->del(1);
                int newNumber = goods[i]->getNumber();
                amount -= (oldNumber - newNumber);
                sumPrice -= (oldNumber - newNumber) * goods[i]->price;
                break;
            }
        }
    }

    // 输出购物车商品清单
    void printList() const {
        for (int i = 0; i < type; i++) {
            goods[i]->print();
        }
        cout << amount << " " << fixed << setprecision(2) << sumPrice << endl;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Shoppingcar cart;
        string operation;
        string id, name, color, size;
        double price;
        int number;

        for (int i = 0; i < n; i++) {
            cin >> operation;
            if (operation == "ADD") {
                cin >> id >> name >> color >> size >> price >> number;
                cart.ADD(id, name, color, size, price, number);
            }
            else if (operation == "DELETE") {
                cin >> id;
                cart.DELETE(id);
            }
            else if (operation == "UP") {
                cin >> id;
                cart.UP(id);
            }
            else if (operation == "DOWN") {
                cin >> id;
                cart.DOWN(id);
            }
        }
        cart.printList();
    }

    return 0;
}