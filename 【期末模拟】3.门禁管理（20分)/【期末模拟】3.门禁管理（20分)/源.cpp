#include<iostream>
#include<string>
#include<cmath>
using namespace std;
template<class T>
bool Validate(T n) {
	n *= 100;
	return ((int)n % 7 == 0);
}
bool Validate2(string n) {
	char letter = n[0];
	int sum = 0;
	for (int i = 0;i < n.length(); i++) {
		if (n[i] == letter) {
			sum++;
		}
	}
	return (sum % 2 == 1);
}
template<class T>
class Card {
private:
	int ID;
	T key;
public:
	Card(int i, T k) :ID(i), key(k){}
	void Check() {
		cout << "Card " << ID;
		if (Validate(key)) {
			cout<< " valid" << endl;
		}
		else {
			cout << " invalid" << endl;
		}
	}
	void Check2() {
		cout << "Card " << ID;
		if (Validate2(key)) {
			cout << " valid" << endl;
		}
		else {
			cout << " invalid" << endl;
		}
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		string type;
		int number;
		cin >> type>>number;
		if (type == "S") {
			int key;
			cin >> key;
			Card<int> card(number, key);
			card.Check();
		}else if (type == "N") {
			double key;
			cin >> key;
			Card<double> card(number, key);
			card.Check();
		}
		else if (type == "M") {
			string key;
			cin >> key;
			Card<string> card(number, key);
			card.Check2();
		}
	}
	return 0;
}