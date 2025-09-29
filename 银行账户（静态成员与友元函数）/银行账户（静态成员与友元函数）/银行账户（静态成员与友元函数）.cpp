#include<iostream>
#include<cstring>
using namespace std;
class Account
{
public:
	Account() {}
	Account(string accno, string name, float balance)
	{
		_accno = accno;
		_accname = name;
		_balance = balance;

	}
	void set(string accno, string name, float balance)
	{
		_accno = accno;
		_accname = name;
		_balance = balance;
		count++; 
	}
	~Account() {}
	void Deposit(float amount)
	{
		_balance += amount;
	}
	void Withdraw(float amount)
	{
		_balance -= amount;
	}
	float Getbalance()
	{
		return _balance;
	}
	void show()
	{
		cout << _accno << ' ' << _accname << ' ';
	}
	static int Getcount()
	{
		return count;
	}
	static void Getrate(float r)
	{
		InterestRate = r;
	}
	friend void Update(Account& a); 
	static int count;
	static float InterestRate;
	string _accno, _accname;
	float _balance;
};
int Account::count = 0;
float Account::InterestRate = 0;
void Update(Account& a)
{
	a._balance = a._balance + a._balance * a.InterestRate;
}
int main()
{
	float rate1;
	cin >> rate1;
	Account::Getrate(rate1);
	int n;
	cin >> n;
	Account* p = new Account[n];
	float sum = 0;
	for (int i = 0;i < n;i++)
	{
		string accno1, name1;
		float balance1, dep1, with1;
		cin >> accno1 >> name1 >> balance1 >> dep1 >> with1;
		p[i].set(accno1, name1, balance1);
		p[i].show();
		p[i].Deposit(dep1);
		cout << p[i].Getbalance() << ' ';
		Update(p[i]);
		cout << p[i].Getbalance() << ' ';
		p[i].Withdraw(with1);
		cout << p[i].Getbalance() << endl;
		sum += p[i].Getbalance();
	}
	cout << sum;
	delete[]p;
	return 0;
}
