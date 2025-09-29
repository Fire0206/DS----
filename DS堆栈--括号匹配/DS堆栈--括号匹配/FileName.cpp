#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isMatch(char left, char right) {
	return	(left == '(' && right == ')') ||
			(left == '[' && right == ']') ||
			(left == '{' && right == '}');
}

bool check(string& str) {
	stack<char> s;
	for (char c : str) {
		if (c == '(' || c == '[' || c == '{') {
			s.push(c);
		}
		else if (c == ')' || c == ']' || c == '}') {
			if (s.empty()) {
				return false;
			}
			if (isMatch(s.top(), c)) {
				s.pop();
			}
			else {
				return false;
			}
		}
	}
	return s.empty();
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		if (check(str)) {
			cout << "ok" << endl;
		}
		else {
			cout << "error" << endl;
		}

	}
	return 0;
}