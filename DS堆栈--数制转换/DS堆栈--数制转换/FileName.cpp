#include<iostream>
#include<stack>
using namespace std;

string convert(int n, int k) {
	stack<int>remainderStack;
	bool isNegative = false;
	if (n < 0) {
		isNegative = true;
		n = -n;
	}
	while (n > 0) {
		int remander = n % k;
		remainderStack.push(remander);
		n = n / k;
	}
	string result = "";
	if (isNegative) result += "-";
	while (!remainderStack.empty()) {
		int digit = remainderStack.top();
		remainderStack.pop();
		if (digit >= 10) {
			result +=(char) (digit - 10 + 'A');
		}
		else {
			result += (char)(digit + '0');
		}
	}
	return result;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << convert(n, k) << endl;
	}
	return 0;
}