#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> q1;  
	queue<int> q2; 
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x % 2 == 0) {
			q2.push(x);
		}
		else {
			q1.push(x);
		}
	}

	bool first = true;  

	while (!q1.empty() && !q2.empty()) {
		if (first) {
			cout << q1.front();
			first = false;
		}
		else {
			cout << " " << q1.front();
		}
		q1.pop();

		if (!q1.empty()) {
			cout << " " << q1.front();
			q1.pop();
			cout << " " << q2.front();
			q2.pop();
		}
	}

	while (!q1.empty()) {
		if (first) {
			cout << q1.front();
			first = false;
		}
		else {
			cout << " " << q1.front();
		}
		q1.pop();
	}

	while (!q2.empty()) {
		if (first) {
			cout << q2.front();
			first = false;
		}
		else {
			cout << " " << q2.front();
		}
		q2.pop();
	}

	return 0;
}
