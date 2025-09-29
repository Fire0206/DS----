#include <iostream>
#include <cstring>
using namespace std;
class CAccount {
protected:
	long account;
	char name[10];
	float balance;
public:
	CAccount(long a, char b[10], float c) {
		account = a;
		strcpy_s(name, b);
		balance = c;
	}
	void deposit(int n) {
		balance += n;
		cout << "saving ok!" << endl;
	}
	void withdraw(int n) {
		if (n <= balance) {
			balance -= n;
			cout << "withdraw ok!" << endl;
		}
		else {
			cout << "sorry! over balance!" << endl;
		}
		
	}
	void check() {
		cout << "balance is " << balance << endl;
	}
};

class CCreditcard :public CAccount {
protected:
	float limit;
public:
	CCreditcard(long a, char b[10], float c,float d): CAccount(a,b,c) {
		limit = d;
	}
	void withdraw(int n) {
		if (n  <= balance + limit) {
			balance -= n;
			cout << "withdraw ok!" << endl;
		}
		else {
			cout << "sorry! over limit!" << endl;
		}
	}
};

int main() {
	long account;
	char name[10];
	float balance;
	float limit;
	int m;
	cin >> account >> name >> balance;
	CAccount Account(account, name, balance);
	Account.check();
	cin >> m;
	Account.deposit(m);
	Account.check();
	cin >> m;
	Account.withdraw(m);
	Account.check();

	cin >> account >> name >> balance>>limit;
	CCreditcard card(account, name, balance, limit);
	card.check();
	cin >> m;
	card.deposit(m);
	card.check();
	cin >> m;
	card.withdraw(m);
	card.check();
	return 0;
}