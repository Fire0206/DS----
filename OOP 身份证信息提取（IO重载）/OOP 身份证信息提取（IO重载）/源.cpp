#include<iostream>
#include<string>
using namespace std;
class Card {
private:
	string year, month, day;
	string data,sex;
public:
	Card(const string &id) :data(id){
		year = id.substr(6, 4);
		month = id.substr(10, 2);
		day = id.substr(12, 2);
		char sexnum = id[16];
		int sexNum = sexnum - '0';
		sex = (sexNum % 2 == 1) ? "ÄÐ" : "Å®";
	}
	friend ostream& operator<<(ostream & cout, Card & card) {
		cout << "year=" << card.year << " month=" << card.month << " day=" << card.day << " sex=" << card.sex << endl;
		return cout;
	}
};
int main() {
	int t;
	cin >> t;
	string id;
	while (t--) {
		cin >> id;
		Card card(id);
		cout << card;
	}
}