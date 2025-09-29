#include <iostream>
using namespace std;
class Retangle {
private:
	int m, n;
	int** matrix;

public:
	Retangle(int a, int b) {
		m = a;
		n = b;
		matrix = new int* [m];
		for (int i = 0;i < m;i++) {
			matrix[i] = new int[n];
		}
	}

	void input() {
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				cin >> matrix[i][j];
			}
		}
	}

	Retangle(const Retangle& re) {
		m = re.n;
		n = re.m;
		matrix = new int* [m];
		for (int i = 0;i < m;i++) {
			matrix[i] = new int[n];
		}
		for (int i = 0; i < re.m; i++) {
			for (int j = 0; j < re.n; j++) {
				matrix[j][re.m - 1 - i] = re.matrix[i][j];
			}
		}
	}

	void print() {
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				cout << matrix[i][j];
					if (j != n - 1) {
						cout << " ";
					}
			}
			cout << endl;
		}
	}

	~Retangle() {
		for (int i = 0;i < m;i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
};

int main()
{
	int t, m, n;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		Retangle re(m, n);
		re.input();
		Retangle re2(re);
		cout << "before:" << endl;
		re.print();
		cout << "after:" << endl;
		re2.print();
		cout << endl;
	}
	return 0;
}