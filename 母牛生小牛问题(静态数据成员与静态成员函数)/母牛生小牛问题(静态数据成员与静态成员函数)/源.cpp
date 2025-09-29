#include<iostream>
using namespace std;

class CCow {
private:
    int age;
public:
    CCow() : age(1) {}
    void grow() { age++; }
    bool isBirth() const { return age >= 4 && age < 11; }
    bool isDead() const { return age >= 11; }
};

int calculateCows(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    CCow** cows = new CCow * [1000000]; 
    int cowCount = 1;
    cows[0] = new CCow();

    for (int year = 2; year <= n; year++) {
        int newBorn = 0;
        int survivingCount = 0;

        for (int i = 0; i < cowCount; i++) {
            cows[i]->grow();
            if (cows[i]->isBirth()) {
                newBorn++;
            }
            if (!cows[i]->isDead()) {
                cows[survivingCount++] = cows[i];
            }
            else {
                delete cows[i]; 
            }
        }

        for (int i = 0; i < newBorn; i++) {
            cows[survivingCount + i] = new CCow();
        }

        cowCount = survivingCount + newBorn;
    }

    int result = cowCount;
    for (int i = 0; i < cowCount; i++) {
        delete cows[i];
    }
    delete[] cows;

    return result;
}

int main() {
    int t, year;
    cin >> t;
    while (t--) {
        cin >> year;
        cout << calculateCows(year) << endl;
    }
    return 0;
}