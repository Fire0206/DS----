#include<iostream>
using namespace std;
class TripCard {
protected:
	int id;
	float  score;
public:
	TripCard(int i, int s):
		id(i), score(s){}
	void comsume(float m) {
		score += m;
	}
};

class CreditCard {
protected:
	int id, limit;
	float  score;
	string name;
	float amount;
public:
	CreditCard(int i, int l, int s, string n, float a) :
		id(i), limit(l), score(s), name(n), amount(a) {}
	void Spend(float m) {
		if (m + amount <= limit) {
			amount += m;
			score += m;
		}
	}
	void Return(float m) {
		amount -= m;
		score -= m;
	}
};

class SumCard :public TripCard, public CreditCard {
public:
	SumCard(int i1, int s1, int i, int l, int s, string n, float a):
		TripCard(i1,s1),CreditCard(i,l,s,n,a){ }
	void exchange(float m) {
		CreditCard::score -= m;
		TripCard::score += m /2;
	}
	int getId1() {
		return TripCard::id;
	}
	int getId2() {
		return CreditCard::id;
	}
	int getScore1() {
		return TripCard::score;
	}
	int getScore2() {
		return CreditCard::score;
	}
	float getAmount() {
		return amount;
	}
};

int main() {
	int id1, id2, limit,n;
	string name;
	cin >> id1 >> id2 >> name >> limit;
	SumCard card(id1, 0, id2, limit, 0, name, 0);
	cin >> n;
	while (n--) {
		char type;
		float m;
		cin >> type>>m;
		switch (type)  {
			case 'o':
				card.comsume(m);
				card.Spend(m);
				break;
			case 'c':
				card.Spend(m);
				break;
			case 'q':
				card.Return(m);
				break;
			case 't':
				card.exchange(m);
				break;
		}
	}
	cout << card.getId1() << " " << card.getScore1() << endl;
	cout << card.getId2() << " " << name << " " << card.getAmount() << " " << card.getScore2() << endl;
	return 0;
}
