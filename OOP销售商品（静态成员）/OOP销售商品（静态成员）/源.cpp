#include<iostream>
#include<iomanip>
using namespace std;
class Seller {
private:
	int id,num;
	double price;
public:
	static double discount;
	static double sum;
	static int totalNum;
	static double average();
	static void display();
	Seller(int _id, int _num, double _price) :id(_id), num(_num), price(_price) {
		totalNum += num;
		if (num > 10) {
			sum += num * price * discount;
		}
		else {
			sum += num * price;
		}
	}
};
double Seller::sum = 0;
double Seller::discount = 0.98;
int Seller::totalNum = 0;
double Seller::average(){
		return double(sum / (totalNum));
}
void Seller::display(){
	cout << "num=" << totalNum << endl;
	cout << "sum=" << fixed << setprecision(2) << sum << endl;
	cout << "average=" << fixed << setprecision(2) << average()<<endl;
}

int main() {
	int id, num;
	double price, discount;
	for (int i = 0;i < 3;i++) {
		cin >> id >> num >> price;
		Seller seller(id, num, price);

	}
	Seller::display();
	return 0;
}