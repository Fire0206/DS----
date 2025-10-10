#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == '(') st.push(')');
		else if (c == '[') st.push(']');
		else if (c == '{') st.push('}');
		else if (c == ')' || c == ']' || c == '}') {
			if (st.empty() || st.top() != c) return false;
			st.pop();
		}
		// 对于普通字符如 a, b, +, -, / 等，不需要处理
	}
	return st.empty();
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (isValid(s)) cout << "ok";
		else cout << "error";
		cout << endl;
	}
	return 0;
}
