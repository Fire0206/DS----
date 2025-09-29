#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<char> q1,q2,q3;
	int n;
	cin >> n;
	char* types = new char[n];
	for (int i = 0; i < n; i++) {
		cin >> types[i];
	}
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		switch (types[i]) {
			case'A':
				q1.push(a);
				break;
			case'B':
				q2.push(a);
				break;
			case'C':
				q3.push(a);
				break;
		}
	}
	int num1 = 0, sum1 = 0;
	while (!q1.empty()) {
		sum1 += q1.front();
		num1++;
		q1.pop();
	}
	int avg1 = sum1 / num1;
	int num2 = 0, sum2 = 0;
	while (!q2.empty()) {
		sum2 += q2.front();
		num2++;
		q2.pop();
	}
	int avg2 = sum2 / num2;
	int num3 = 0, sum3 = 0;
	while (!q3.empty()) {
		sum3 += q3.front();
		num3++;
		q3.pop();
	}
	int avg3 = sum3 / num3;
	cout << avg1 << endl;
	cout << avg2 << endl;
	cout << avg3 << endl;
}