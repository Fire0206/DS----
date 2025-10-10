#include<iostream>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

char digitToChar(int d) {
	if (d < 10) return '0' + d;
	return 'A' + (d - 10);
}

string convert(double n, int k) {
	int integerPart = (int)n;
	double fracPart = n - integerPart;
	stack<int> st;
	if (integerPart == 0) st.push(0);
	while (integerPart > 0) {
		int remainder = integerPart % k;
		st.push(remainder);
		integerPart /= k;
	}
	string intStr;
	while (!st.empty()) {
		int d = st.top();
		st.pop();
		intStr.push_back(digitToChar(d));
	}

	queue<int> q;
	for (int i = 0; i < 3; i++) {
		fracPart *= k;
		int digit = (int)fracPart;
		q.push(digit);
		fracPart -= digit;
	}
	string fracStr;
	while (!q.empty()) {
		int d = q.front();
		q.pop();
		fracStr.push_back(digitToChar(d));
	}
	return intStr + "." + fracStr;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		double n;
		int k;
		cin >> n >> k;
		cout << convert(n, k) << endl;
	}
	return 0;
}