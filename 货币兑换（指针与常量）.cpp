#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    const double USD_RATE = 6.2619;
    const double EUR_RATE = 6.6744;
    const double JPY_RATE = 0.0516;
    const double HKD_RATE = 0.8065;

    int t;
    cin >> t;
    const double* ratePtr;

    for (int i = 0; i < t; ++i) {
        char type;
        double num;
        cin >> type >> num;
        switch (type) {
            case 'D':
                ratePtr = &USD_RATE;
                break;
            case 'E':
                ratePtr = &EUR_RATE;
                break;
            case 'Y':
                ratePtr = &JPY_RATE;
                break;
            case 'H':
                ratePtr = &HKD_RATE;
                break;
        }
        double rmb = num * (*ratePtr);
		cout << fixed << setprecision(4) << rmb << endl;
    }
    return 0;
}
