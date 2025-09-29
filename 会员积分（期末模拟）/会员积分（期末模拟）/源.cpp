#include <iostream>
#include<string>
using namespace std;
class Member {
protected:
	int id,score;
	string name;
public:
	Member(int i, int s, string n) :id(i), score(s), name(n) {}
	virtual void Add(int m) {
		score += m;
	}
	virtual int Exchange(int m) {
		int temp = m / 100;
		score -= 100*temp;
		return temp;
	}
	virtual void Print() {
		cout << "普通会员" << id << "--" << name << "--" << score << endl;
	}
};
class VIP :public Member {
private:
	int addRate, exchangeRate;
public:
	VIP(int i, int s, string n,int a,int e):Member(i,s,n),addRate(a),exchangeRate(e){}
	void Add(int m) override{
		score += m * addRate;
	}
	int Exchange(int m)override {
		int temp = m / exchangeRate;
		score -= temp * exchangeRate;
		return temp;
	}
	void Print()override {
		cout << "贵宾会员" << id << "--" << name << "--" << score << endl;
	}
};

int main() {
	Member* pm = nullptr;
	int id, score;
	string name;
	int addRate, exchangeRate;
	int m;

	cin >> id >> name >> score;
	pm = new Member(id, score, name);
	cin >> m;
	pm->Add(m);
	cin >> m;
	pm->Exchange(m);
	pm->Print();

	cin >> id >> name >> score >> addRate >> exchangeRate;
	pm = new VIP(id, score, name, addRate, exchangeRate);
	cin >> m;
	pm->Add(m);
	cin >> m;
	pm->Exchange(m);
	pm->Print();

	return 0;
}