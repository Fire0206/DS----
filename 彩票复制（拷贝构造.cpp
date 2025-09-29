#include <iostream>
using namespace std;

class Lottery {
    int group1[6];
    int num;
    int **groupn;

public:
    Lottery(int a[], int n) {
        for (int i = 0; i < 6; i++) {
            group1[i] = a[i];
        }
        num = n;
        groupn = NULL;
    }

    Lottery(const Lottery &lo) {
        for (int i = 0; i < 6; i++) {
            group1[i] = lo.group1[i];
        }
        num = lo.num;
        groupn = new int*[num + 1];
        for (int i = 0; i < num + 1; i++) {
            groupn[i] = new int[6];
        }
        for (int i = 0; i < 6; i++) {
            groupn[0][i] = lo.group1[i];
        }
        for (int i = 1; i < (num + 1); i++) {
            groupn[i][0] = groupn[i - 1][5] + 1;
            for (int j = 1; j < 6; j++) {
                groupn[i][j] = groupn[i - 1][j - 1] + 1;
            }
        }
    }

    void print() {
        if (!groupn) return;
        for (int i = 0; i < (num + 1); i++) {
            for (int j = 0; j < 6; j++) {
                cout << groupn[i][j];
                if (j != 5) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    ~Lottery() {
        if (groupn) {
            for (int i = 0; i < num + 1; i++) {
                delete[] groupn[i];
            }
            delete[] groupn;
        }
    }
};

int main() {
    int t, n;
    int a[6];
    cin >> t;
    while (t--) {
        for (int i = 0; i < 6; i++) {
            cin >> a[i];
        }
        cin >> n;
        Lottery lo1(a, n);
        Lottery lo2(lo1);
        lo2.print();
    }
    return 0;
}
