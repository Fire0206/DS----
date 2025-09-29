#include<iostream>
#include<string>
using namespace std;

class Account {
private:
	static int count;
	static float InterestRate;
	string _accno, _accname;
	float _balance;

public:
	Account(string accno, string name, float balance) {
		_accno = accno;
		_accname = name;
		_balance = balance;
	}
	~Account();
	void Deposit(float amonut){

	}
};