#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class CBook {
	string name, author,house;
	double price;
public:
	friend ostream& operator<<(ostream& cout, CBook& book);
	friend istream& operator>>(istream& cin, CBook& book);
	friend void find(CBook* book, int n, int& max1index, int& max2index);
};
istream& operator>>(istream& cin, CBook& book) {
	char c;
	getline(cin, book.name, ',');
	getline(cin, book.author,',');
	cin >> book.price;
	cin >> c;
	getline(cin, book.house, '\n');
	return cin;
}
ostream& operator<<(ostream& cout, CBook& book) {
	cout << book.name << endl;
	cout << book.author << endl;
	cout << fixed << setprecision(2) << book.price << endl;
	cout << book.house;
	return cout;
}
void find(CBook* book, int n, int& max1index, int& max2index) {
	double max = 0;
	double max2 = 0;
	for (int i = 0;i < n;i++) {
		if (book[i].price > max) {
			max = book[i].price;
			max1index = i;
		}
	}
	for (int i = 0;i < n;i++) {
		if (book[i].price > max2&&i!=max1index) {
			max2 = book[i].price;
			max2index = i;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		CBook* books = new CBook[n];
		for (int i = 0;i < n;i++) {
			cin >> books[i];
		}
		int max = 0;
		int min = 0;
		find(books, n, max, min);
		cout << books[max]<<endl;
		cout << endl;
		cout << books[min];
		if (t != 0) {
			cout << endl;
		}
	}
	return 0;
}