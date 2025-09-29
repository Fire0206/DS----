#include<iostream>
using namespace std;
class Group
{
public:
	virtual int add(int x, int y) = 0;//输出加法的运算结果

	virtual int sub(int x, int y) = 0;//输出减法的运算结果
};
class GroupA :public Group {
public :
	int add(int x, int y) {
		return (x + y);
	}
	int sub(int x, int y) {
		return (x - y);
	}
};
class GroupB :public Group {
public:
	int add(int x, int y) {
		return (x + y);
	}
	int sub(int x, int y) {
		int sum = 0;
		int power = 1;
		while (x > 0 || y > 0) {
			sum += (((x % 10) + 10 - y % 10) % 10) * power;
			x /= 10;
			y /= 10;
			power *= 10;
		}
		return sum;
	}
};
class GroupC :public Group {
public:
	int add(int x, int y) {
		int sum = 0;
		int power = 1;
		while (x > 0 || y > 0) {
			sum += (((x % 10) + (y % 10)) % 10) * power;
			x /=10;
			y /= 10;
			power *= 10;
		}
		return sum;
	}
	int sub(int x, int y) {
		int sum = 0;
		int power = 1;
		while (x > 0 || y > 0) {
			sum += (((x % 10) + 10 - y % 10) % 10) * power;
			x /=10;
			y /=10;
			power *=10;
		}
		return sum;
	}
};
int main() {
	int t;
	cin >> t;
	int type,x,y;
	char op;
	Group* gr = nullptr;
	while (t--) {
		cin >> type>>x>>op>>y;
		if (type == 1) {
			gr = new GroupA();			
		}
		else if (type == 2){
			gr = new GroupB();
		}
		else if (type == 3) {
			gr = new GroupC();
		}
		if (op == '+') {
			cout << gr->add(x, y) << endl;
		}
		else {
			cout << gr->sub(x, y) << endl;
		}
	}
	return 0;
}