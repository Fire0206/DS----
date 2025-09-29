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
    Goods(string id, string name, string color, string size, double price, int number)
        : id(id), name(name), color(color), size(size), price(price), number(number) {}

    double totalPrice() const {
        return price * number;
    }

    void print() const {
        cout << name << "," << color << "," << size << "," << fixed << setprecision(2) << price << "," << number << "," << totalPrice() << endl;
    }

    void add(int a) {
        number += a;
    }

    void del(int a) {
        if (number - a >= 1) {
            number -= a;
        }
    }

    string getID() const {
        return id;
    }

    int getNumber() const {
        return number;
    }

    double getPrice() const {
        return price;
    }
};

class Shoppingcar {
private:
    Goods* goods[100];
    int type;
    int amount;
    double sumPrice;

public:
    Shoppingcar() : type(0), amount(0), sumPrice(0) {
        for (int i = 0; i < 100; i++) {
            goods[i] = NULL;
        }
    }

    ~Shoppingcar() {
        for (int i = 0; i < type; i++) {
            delete goods[i];
        }
    }

    void ADD(string id, string name, string color, string size, double price, int number) {
        for (int i = 0; i < type; i++) {
            if (goods[i]->getID() == id) {
                goods[i]->add(number);
                amount += number;
                sumPrice += price * number;
                return;
            }
        }
        for (int i = type; i > 0; i--) {
            goods[i] = goods[i - 1];
        }
        goods[0] = new Goods(id, name, color, size, price, number);
        type++;
        amount += number;
        sumPrice += price * number;
    }

    void DELETE(string id) {
        for (int i = 0; i < type; i++) {
            if (goods[i]->getID() == id) {
                amount -= goods[i]->getNumber();
                sumPrice -= goods[i]->totalPrice();
                delete goods[i];
                for (int j = i; j < type - 1; j++) {
                    goods[j] = goods[j + 1];
                }
                goods[type - 1] = NULL;
                type--;
                break;
            }
        }
    }

    void UP(string id) {
        for (int i = 0; i < type; i++) {
            if (goods[i]->getID() == id) {
                goods[i]->add(1);
                amount++;
                sumPrice += goods[i]->getPrice();
                break;
            }
        }
    }

    void DOWN(string id) {
        for (int i = 0; i < type; i++) {
            if (goods[i]->getID() == id) {
                int oldNumber = goods[i]->getNumber();
                goods[i]->del(1);
                int newNumber = goods[i]->getNumber();
                amount -= (oldNumber - newNumber);
                sumPrice -= (oldNumber - newNumber) * goods[i]->getPrice();
                break;
            }
        }
    }

    void printList() const {
        cout << "商品清单:" << endl;
        cout << "商品,颜色,尺码,单价,数量,小计" << endl;
        for (int i = 0; i < type; i++) {
            goods[i]->print();
        }
        cout << "----------" << endl;
        cout << amount << "件商品,总商品金额" << fixed << setprecision(2) << sumPrice << endl;
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
            } else if (operation == "DELETE") {
                cin >> id;
                cart.DELETE(id);
            } else if (operation == "UP") {
                cin >> id;
                cart.UP(id);
            } else if (operation == "DOWN") {
                cin >> id;
                cart.DOWN(id);
            }
        }
        cart.printList();
    }

    return 0;
}    
