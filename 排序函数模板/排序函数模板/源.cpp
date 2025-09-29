#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
class Point {
private:
	double x, y;
public:
	friend istream& operator>>(istream& is,Point& p) {
		is >> p.x >> p.y;
		return is;
	}
	friend ostream& operator<<(ostream& os,const Point& p) {
		os << "(" <<fixed<<setprecision(1)  << p.x << ", " << fixed << setprecision(1) << p.y << ")";
		return os;
	}
	double dis() {
		return x * x + y * y;
	}
};
bool operator<(Point& a,Point& b) {
	return a.dis() < b.dis();
}
template<class T>
void mysort(T arr[],int len) {
	for (int i = 0;i < len;i++) {
		int min = i;
		for (int j = i+1;j <len;j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		std::swap(arr[min], arr[i]);
	}
	for (int i = 0;i < len;i++) {
		cout << arr[i]<<" ";
	}
	cout << endl;
}
template<class T>
void func() {
	int len;
	cin >> len;
	T* arr = new T[len];
	for (int i = 0;i < len;i++) {
		cin >> arr[i];
	}
	mysort(arr, len);
	delete[] arr;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		char type;
		cin >> type;
		if (type == 'I') {
			func<int>();
		}
		else if (type == 'S') {
			func<string>();
		}
		else if (type == 'D') {
			func<double>();
		}
		else if (type == 'P') {
			func<Point>();
		}
	}
	return 0;
}