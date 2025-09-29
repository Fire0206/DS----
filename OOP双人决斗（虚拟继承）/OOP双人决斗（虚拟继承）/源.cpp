#include <iostream>
#include <string>
using namespace std;
class Node2D {
protected:
	string location;
public:
	Node2D(string l) {
		location = l;
	}
};
class Body :virtual public Node2D {
protected:
	int health;
	int defense;
public:
	Body(string l, int he, int de):Node2D(l),health(he),defense(de) {}
};
class Weapon :virtual  public Node2D{
protected:
	string wname;
	int damage;
public:
	Weapon(string l,string na, int da) :Node2D(l),wname(na),damage(da) {}
};
class Player :public Body, public Weapon {
private:
	string name;
public:
	Player(string l, int he, int de, string na, int da,string n):
		Node2D(l), Body(l,  he,  de), Weapon(l,na,da), name(n) { }
	void attack(const Player & p1) {
		health -= p1.damage - defense;
	}
	bool live(){
		return health > 0;
	}
	void display(const Player& p1) {
		cout << p1.name << " deal " << p1.damage - defense << " damage to " << name<<endl;
		if (live()) {
			cout << name << " still have " << health << " health" << endl;
			cout << endl;
		}
		else {
			cout << p1.name << " defeated " << name << " by " << p1.wname << " in " << location << endl;
		}
	}
};
int main() {
	string location;
	int health;
	int defense;
	string wname;
	int damage;
	string name;
	cin >> location;
	cin >> name >> health >> defense >> wname >> damage;
	Player p1(location, health, defense, wname, damage, name);
	cin >> name >> health >> defense >> wname >> damage;
	Player p2(location, health, defense, wname, damage, name);
	while (p1.live() && p2.live()){
		p2.attack(p1);
		p2.display(p1);
		if (p2.live() != 1) {
			break;
		}
		p1.attack(p2);
		p1.display(p2);
	}
	return 0;
}