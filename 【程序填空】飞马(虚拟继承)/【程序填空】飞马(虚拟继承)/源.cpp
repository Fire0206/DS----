#include <iostream>
#include <string>
using namespace std;
class Player {
protected:
    string name;
    int height;
    int weight;
public:
    Player(string n, int h, int w) : name(n), height(h), weight(w) {}
    virtual void display() {
        cout << "Player:" << endl;
        cout << "name:" << name << endl;
        cout << "height:" << height << endl;
        cout << "weight:" << weight << endl;
    }
};

class MVP : virtual public Player {
protected:
    int year;
public:
    MVP(string n, int h, int w, int y) : Player(n, h, w), year(y) {}
    void display() override {
        cout << "MVP:" << endl;
        cout << "name:" << name << endl;
        cout << "height:" << height << endl;
        cout << "weight:" << weight << endl;
        cout << "reward:win the MVP reward in " << year << endl;
    }
};

class DPOY : virtual public Player {
protected:
    int year;
public:
    DPOY(string n, int h, int w, int y) : Player(n, h, w), year(y) {}
    void display() override {
        cout << "DPOY:" << endl;
        cout << "name:" << name << endl;
        cout << "height:" << height << endl;
        cout << "weight:" << weight << endl;
        cout << "reward:win the DPOY reward in " << year << endl;
    }
};

class HallOfFame : public MVP, public DPOY {
public:
    HallOfFame(string n, int h, int w, int y1, int y2) : MVP(n, h, w, y1), DPOY(n, h, w, y2), Player(n, h, w) {}
    void display() override {
        cout << "Hall of fame:" << endl;
        cout << "name:" << name << endl;
        cout << "height:" << height << endl;
        cout << "weight:" << weight << endl;
        cout << "reward1:win the MVP reward in " << MVP::year << endl;
        cout << "reward2:win the DPOY reward in " << DPOY::year << endl;
    }
};

int main() {
    string name;
    int height, weight, year1, year2;
    cin >> name >> height >> weight;
    cin >> year1;
    cin >> year2;

    Player p(name, height, weight);
    MVP m(name, height, weight, year1);
    DPOY d(name, height, weight, year2);
    HallOfFame h(name, height, weight, year1, year2);

    p.display();
    cout << endl;
    m.display();
    cout << endl;
    d.display();
    cout << endl;
    h.display();

    return 0;
}