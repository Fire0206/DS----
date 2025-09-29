#include<iostream>
#include<string>
using namespace std;
template<class T>
void myswap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<class T>
int find(T arr[], int len, T key) {
	for (int i = 0;i < len;i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}
template<class T>
void sort(T arr[], int len) {
	for (int i = 0;i < len;i++) {
		int min = i;
		for (int j = i+1;j < len;j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		myswap(arr[i], arr[min]);
	}
	for (int i = 0;i < len;i++) {
		cout << arr[i] << " ";
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
	sort(arr, len);
	T key;
	cin >> key;
	cout << find(arr, len, key) << endl;
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
		else if (type == 'D') {
			func<double>();
		}
		else if (type == 'C') {
			func<char>();
		}
		else if (type == 'S') {
			func<string>();
		}
	}
	return 0;
}