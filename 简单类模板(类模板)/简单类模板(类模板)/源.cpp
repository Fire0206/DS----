#include<iostream>
using namespace std;
template<class T>
class list {
private:
	T arr[100];
	int n;
public:
	list(int n1, T a[]) :n(n1) {
		for (int i = 0;i < n;i++) {
			arr[i] = a[i];
		}
	}
	void insert(int place, T num) {
		for (int i = n; i > place; i--) {
			arr[i] = arr[i - 1];
		}
		arr[place] = num;
		n++;
	}
	void Delete(int place) {
		for (int i = place; i < n - 1; i++) {
			arr[i] = arr[i + 1];
		}
		n--;
	}
	void Print() {
		for (int i = 0;i < n;i++) {
			if (arr[i] != -1) {
				cout << arr[i];
				if (i != n - 1) {
					cout << " ";
				}
			}
		}
		cout << endl;
	}
};
int main() {
	int n,place,num;
	cin >> n;
	int arr[100] = { -1 };
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	list<int> l1(n, arr);
	cin >> place >> num;
	l1.insert(place, num);
	cin >> place;
	l1.Delete(place);
	l1.Print();

	double num2;
	cin >> n;
	double arr2[100] = { -1.0 };
	for (int i = 0;i < n;i++) {
		cin >> arr2[i];
	}
	list<double> l2(n, arr2);
	cin >> place >> num2;
	l2.insert(place, num2);
	cin >> place;
	l2.Delete(place);
	l2.Print();
	return 0;
}