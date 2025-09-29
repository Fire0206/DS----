#include<iostream>
#include<queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<char> qq;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        qq.push(x);
    }

    if (!qq.empty()) {
        cout << qq.front() << " " << qq.back() << endl;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        if (!qq.empty()) {
            qq.pop();
        }
    }

    bool first = true;
    while (!qq.empty()) {
        if (!first) {
            cout << " ";
        }
        cout << qq.front();
        qq.pop();
        first = false;
    }

    cout << endl;

    return 0;
}