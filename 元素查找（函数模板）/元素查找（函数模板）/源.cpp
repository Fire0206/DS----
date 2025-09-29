#include<iostream>
using namespace std;
template<class T>
int find(T arr[], int len, T key) {
	for (int i = 0;i < len;i++) {
		if (arr[i] == key) {
			return i ;
		}
	}
	return -1;
}
template<class T>
void func() {
	int len;
	cin >> len;
		T* arr = new T[len];
		for (int i = 0;i < len;i++) {
			cin >> arr[i];
		}
		T key;
		cin >> key;
		cout << find(arr, len, key)+1 << endl;
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