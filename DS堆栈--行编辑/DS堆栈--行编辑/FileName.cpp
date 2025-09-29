#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		stack<char> s;
		for (char c : str) {
			if (c == '#') {
				if (!s.empty()) {
					s.pop();
				}
			}
			else {
				s.push(c);
			}
		}
		stack<char> temp;
		while (!s.empty()) {
			temp.push(s.top());
			s.pop();
		}
		if (temp.empty()) {
			cout << "NULL" << endl;
		}
		else {
			while (!temp.empty()) {
				cout << temp.top();
				temp.pop();
			}
			cout << endl;
		}
	}
	return 0;

}