#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    unordered_map<int, int> belong;
    for (int i = 0; i < t; i++) {
        int n, x;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> x;
            belong[x] = i;
        }
    }

    queue<int> groupQ;
    vector<queue<int>> groupQueue(t);
    vector<bool> inQ(t, false);

    string cmd;
    bool first = true;  // 控制输出空格

    while (cin >> cmd) {
        if (cmd == "STOP") {
            cout << endl;
            break;
        }
        else if (cmd == "ENQUEUE") {
            int x; cin >> x;
            int g = belong[x];                 // 题目保证x在某组里
            if (!inQ[g]) {                     // 该组还不在队列里
                groupQ.push(g);
                inQ[g] = true;
            }
            groupQueue[g].push(x);             // 入该组队尾
        }
        else if (cmd == "DEQUEUE") {
            int g = groupQ.front();
            int val = groupQueue[g].front();
            groupQueue[g].pop();

            if (!first) cout << " ";
            cout << val;
            first = false;

            if (groupQueue[g].empty()) {       // 该组空了，移出组队列
                groupQ.pop();
                inQ[g] = false;
            }
        }
    }
    return 0;
}