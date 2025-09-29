#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Player {
protected:
	char name[20];
	float height, weight;
public:
	Player() {
	}
	Player(char* n, float h, float w) {
		strcpy(name, n);
		height = h;
		weight = w;
	}
	void print() {
		cout << "球员姓名:" << name << " 身高:" << height << " 体重:" << weight << endl;
	}
};

class MVP : public Player {
protected:
	int year;
	float score, lb, zg;
public:
	MVP() {}
	MVP(int y, float s, float l, float z) {
		year = y;
		score = s;
		lb = l;
		zg = z;
	}
	int win() {
		if (score > 25 && lb > 6 && zg > 6) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void print() {
		cout << "MVP年份:" << year << fixed << setprecision(1) << " 得分:" << score << " 篮板:" << lb << " 助攻:" << zg << endl;
	}
};

class DPOY : public Player {
protected:
	int year;
	float lb, qd, gm;
public:
	DPOY() {
	}
	DPOY(int y, float l, float q, float g) {
		year = y;
		lb = l;
		qd = q;
		gm = g;
	}
	int win() {
		if (lb > 12 && gm > 2.5 && qd > 1.5) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void print() {
		cout << "DPOY年份:" << year << fixed << setprecision(1) << " 盖帽:" << gm << " 篮板:" << lb << " 抢断:" << qd << endl;
	}
};

int main() {
	int year;
	int i = 0;
	float w, h, score, lb, zg, gm, qd;
	char name[20];
	cin >> name >> h >> w;
	Player a(name, h, w);
	MVP* p[12];
	DPOY* q[12];
	year = 2010;
	for (i = 0; i < 12; i++) {
		cin >> score >> lb >> zg >> gm >> qd;
		p[i] = new MVP(year, score, lb, zg);
		q[i] = new DPOY(year, lb, qd, gm);
		year++;
	}
	a.print();
	for (i = 0; i < 12; i++) {
		if (p[i]->win()) {
			p[i]->print();
		}
	}
	for (i = 0; i < 12; i++) {
		if (q[i]->win()) {
			q[i]->print();
		}
	}
}