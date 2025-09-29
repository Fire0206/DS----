#include<iostream>
using namespace std;
class CXGraph {
private:
	int n;
public:
	CXGraph(int a) :n(a) {}
	friend ostream& operator<<(ostream& cout, CXGraph x) {
		for (int i = 0;i < x.n / 2;i++) {
			for (int j = 0;j < i;j++) {
				cout << " ";
			}
			for (int v = 0;v < (x.n - i * 2);v++) {
				cout << "X";
			}
			cout << endl;
		}
		for (int i = 0;i < (x.n / 2 + 1);i++) {
			for (int j = 0;j < x.n / 2 - i;j++) {
				cout << " ";
			}
			for (int v = 0;v < 2 * (i + 1) - 1;v++) {
				cout << "X";
			}
			cout << endl;
		}
		return cout;
	}
	CXGraph& operator++() {
		if (n < 21)
			n += 2;
		return *this;
	}
	CXGraph operator++(int) {
		CXGraph temp = *this;
		if (n < 21)
			n += 2;
		return temp;
	}
	CXGraph& operator--() {
		if (n > 1)
			n -= 2;
		return *this;
	}
	CXGraph operator--(int) {
		CXGraph temp = *this;
		if (n > 1)
			n -= 2;
		return temp;
	}
};
int main() {
	int t, n;
	string command;
	cin >> n;
	CXGraph xGraph(n);
	cin >> t;
	while (t--) {
		cin >> command;
		if (command == "show++") {
			cout << xGraph++ << endl;
		}
		else if (command == "++show") {
			cout << ++xGraph << endl;
		}
		else if (command == "show--") {
			cout << xGraph-- << endl;
		}
		else if (command == "--show") {
			cout << --xGraph << endl;
		}
		else if (command == "show") {
			cout << xGraph << endl;
		}
	}
	return 0;
}