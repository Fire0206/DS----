#include <iostream>
#include <string>
using namespace std;

struct Stu {
    int id;
    string a1;
    string a2;
    string a3;
};

double similarity(const string& s1, const string& s2) {
    int minLen = min(s1.length(), s2.length());
    int sameCount = 0;
    for (int i = 0; i < minLen; ++i) {
        if (s1[i] == s2[i]) {
            ++sameCount;
        }
    }
    return (double)sameCount / min(s1.length(), s2.length());
}

int find(const Stu* stu1, const Stu* stu2) {
    if (similarity(stu1->a1, stu2->a1) >= 0.9) {
        return 1;
    }
    if (similarity(stu1->a2, stu2->a2) >= 0.9) {
        return 2;
    }
    if (similarity(stu1->a3, stu2->a3) >= 0.9) {
        return 3;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    Stu* stu = new Stu[t];

    for (int i = 0; i < t; ++i) {
        cin >> stu[i].id;
        cin.ignore();
        getline(cin, stu[i].a1);
        getline(cin, stu[i].a2);
        getline(cin, stu[i].a3);
    }

    for (int i = 0; i < t; ++i) {
        for (int j = i + 1; j < t; ++j) {
            int result = find(&stu[i], &stu[j]);
            if (result != 0) {
                cout << stu[i].id << " " << stu[j].id << " " << result << endl;
            }
        }
    }
    delete[] stu;
    return 0;
}
