#include<iostream>
using namespace std;
template<class T>
class Matrix {
private:
	int m, n;
	T** data;
public:
	Matrix(int m1, int n1) :m(m1), n(n1) {
		data = new T*[m];
		for (int i = 0;i < m;i++) {
			data[i] = new T[n];
		}
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				cin >> data[i][j];
			}
		}
	}
	~Matrix() {
		for (int i = 0;i < m;i++) {
			delete[] data[i];
		}
		delete[] data;
	}
	void transport() {
		T** tempData = new T * [n];
		for (int i = 0; i < n; i++) {
			tempData[i] = new T[m];
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				tempData[j][i] = data[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			delete[] data[i];
		}
		delete[] data;
		data = tempData;
		swap(m, n);
	}
	void print() {
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				cout << data[i][j];
				if (j == n - 1) {
					cout << endl;
				}
				else {
					cout << " ";
				}
			}
		}
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		char type;
		int m, n;
		cin >> type>>m>>n;
		if (type == 'I') {
			Matrix<int> mat(m,n);
			mat.transport();
			mat.print();
		}
		else if (type == 'D') {
			Matrix<double> mat(m, n);
			mat.transport();
			mat.print();
		}
		else if (type == 'C') {
			Matrix<char> mat(m, n);
			mat.transport();
			mat.print();
		}
	}
	return 0;
}