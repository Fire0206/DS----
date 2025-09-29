#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string id;
    int de, cai, sum, type;
};

bool cmp(const Student &a, const Student &b) {
    if (a.type != b.type) return a.type < b.type;
    if (a.sum != b.sum) return a.sum > b.sum;
    if (a.de != b.de) return a.de > b.de;
    return a.id < b.id;
}

int main() {
    int N, L, H;
    cin >> N >> L >> H;
    vector<Student> v;
    for (int i = 0; i < N; i++) {
        Student s;
        cin >> s.id >> s.de >> s.cai;
        if (s.de < L || s.cai < L) continue;
        s.sum = s.de + s.cai;
        if (s.de >= H && s.cai >= H) s.type = 1;
        else if (s.de >= H && s.cai < H) s.type = 2;
        else if (s.de < H && s.cai < H && s.de >= s.cai) s.type = 3;
        else s.type = 4;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.size() << endl;
    for (auto &s : v) {
        cout << s.id << " " << s.de << " " << s.cai << endl;
    }
    return 0;
}

