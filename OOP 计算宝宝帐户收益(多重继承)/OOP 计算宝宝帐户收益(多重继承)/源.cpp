//完成类定义
/********** Write your code here! **********/
#include <iostream>
#include <cstring>
using namespace std;

class Cpeople {
protected:
	string id;
	string name;
public:
	Cpeople() {
	}
	Cpeople(string i, string n) {
		id = i;
		name = n;
	}
};

class CInternetUser : virtual public Cpeople {
protected:
	string password;
public:
	CInternetUser() {}
	CInternetUser(string i, string n, string p) : Cpeople(i, n), password(p) {

	}
	void registerUser(string na, string i, string pa) {
		id = i;
		name = na;
		password = pa;
	}
	int login(string inid, string inpass) {
		int tag1, tag2;
		if (inid == id) {
			tag1 = 0;
		}
		else {
			tag1 = 1;
		}
		if (inpass == password) {
			tag2 = 0;
		}
		else {
			tag2 = 1;
		}
		if (tag1 == 0 && tag2 == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}

};

class CBankCustomer : virtual public Cpeople {
protected:
	double balance;
public:
	CBankCustomer() {
		balance = 0;
	}
	void openAccount(string na, string i) {
		name = na;
		id = i;
	}
	void deposit(double depo) {
		balance += depo;
	}
	int withdraw(double with) {
		if (balance - with >= 0) {
			balance -= with;
			return 1;
		}
		else {
			return 0;
		}
	}
};

class CInternetBankCustomer : public CBankCustomer, public CInternetUser {
	double rest, yesrest, todayin, todayinterest, yesinterest;
public:
	int login(string inid, string inpass) {
		int tag2, tag3;
		int tag1 = CInternetUser::login(inid, inpass);
		if (CInternetUser::id == CBankCustomer::id) {
			tag2 = 0;
		}
		else {
			tag2 = 1;
		}
		if (CInternetUser::name == CInternetUser::name) {
			tag3 = 0;
		}
		else {
			tag3 = 1;
		}
		if (tag1 == 0 && tag2 == 0 && tag3 == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	CInternetBankCustomer() {
		rest = 0;
		yesrest = 0;
		todayin = 0;
		todayinterest = 0;
		yesinterest = 0;
	}
	int deposit(double depo) {
		if (CBankCustomer::withdraw(depo)) {
			rest += depo;
			return 1;
		}
		else {
			return 0;
		}
	}
	int withdraw(double with) {
		if (rest - with >= 0) {
			rest -= with;
			CBankCustomer::deposit(with);
			return 1;
		}
		else {
			return 0;
		}
	}
	void setInterest(double inte) {
		yesinterest = todayinterest;
		todayinterest = inte;
	}
	void calculateProfit() {
		todayin = yesrest * 0.0001 * yesinterest;
		rest += todayin;
		yesrest = rest;
		yesinterest = todayinterest;
	}
	void print() {
		cout << "Name: " << name << " ID: " << id << endl << "Bank balance: " << balance << endl
			<< "Internet bank balance: " << rest << endl;
	}
};



/*******************************************/
//主函数
int main()
{
    int t, no_of_days, i;
    string i_xm, i_id, i_mm, b_xm, b_id, ib_id, ib_mm;
    double money, interest;char op_code;//输入测试案例数t
    cin >> t;
    while (t--) {//输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;//输入银行开户用户名,id
        cin >> b_xm >> b_id;//输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;
        CInternetBankCustomer ib_user;
        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);
        if (!ib_user.login(ib_id, ib_mm)) //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }//输入天数
        cin >> no_of_days;
        for (i = 0; i < no_of_days; i++) {//输入操作代码, 金额, 当日万元收益
            cin >> op_code >> money >> interest;
            switch (op_code) {
            case 'S': //从银行向互联网金融帐户存入
            case 's': if (!ib_user.deposit(money)) {
                cout << "Bank balance not enough" << endl;
                continue;
            }
                    break;
            case 'T': //从互联网金融转入银行帐户
            case 't':if (!ib_user.withdraw(money)) {
                cout << "Internet bank balance not enough" << endl;
                continue;
            }                        break;
            case 'D': //直接向银行帐户存款
            case 'd':ib_user.CBankCustomer::deposit(money);
                break;
            case 'W': //直接从银行帐户取款
            case 'w':if (!ib_user.CBankCustomer::withdraw(money)) {
                cout << "Bank balance not enough" << endl;
                continue;
            }
                    break;
            default:cout << "Illegal input" << endl;
                continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();//输出用户名,id//输出银行余额 //输出互联网金融账户余额
            ib_user.print();
            cout << endl;
        }
    }
    return 0;
}
