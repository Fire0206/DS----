#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

struct Customer {
    int arrive, process, vip;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Customer> all(N);
    for (int i = 0; i < N; ++i) {
        cin >> all[i].arrive >> all[i].process >> all[i].vip;
        if (all[i].process > 60) all[i].process = 60;
    }

    int K, vip_win;
    cin >> K >> vip_win;

    vector<int> end_time(K, 0);
    vector<int> cnt(K, 0);

    long long total_wait = 0;
    int max_wait = 0;
    int last_finish = 0;

    queue<Customer> Q;
    int idx = 0;
    int current_time = 0;

    auto enqueue_arrivals = [&]() {
        while (idx < N && all[idx].arrive <= current_time) {
            Q.push(all[idx]);
            ++idx;
        }
        };

    auto assign_to_window = [&](int win, const Customer& c, int start_time) {
        int wait = start_time - c.arrive;
        if (wait < 0) wait = 0;
        total_wait += wait;
        if (wait > max_wait) max_wait = wait;
        end_time[win] = start_time + c.process;
        if (end_time[win] > last_finish) last_finish = end_time[win];
        cnt[win]++;
        };

    auto pop_first_vip_from_Q = [&]() -> pair<bool, Customer> {
        if (Q.empty()) return { false, Customer{} };
        queue<Customer> tmp;
        bool found = false;
        Customer vipc{};
        while (!Q.empty()) {
            Customer c = Q.front(); Q.pop();
            if (!found && c.vip == 1) {
                vipc = c;
                found = true;
            }
            else {
                tmp.push(c);
            }
        }
        Q = std::move(tmp);
        return { found, vipc };
        };

    while (idx < N || !Q.empty()) {
        enqueue_arrivals();

        bool progressed = false;

        while (true) {
            bool made_assign = false;

            if (end_time[vip_win] <= current_time) {
                if (!Q.empty()) {
                    auto res = pop_first_vip_from_Q();
                    if (res.first) {
                        Customer c = res.second;
                        assign_to_window(vip_win, c, current_time);
                        made_assign = true;
                    }
                }
            }

            for (int w = 0; w < K; ++w) {
                if (end_time[w] > current_time) continue;
                if (Q.empty()) break;
                if (Q.front().vip == 1 && end_time[vip_win] <= current_time && w != vip_win) {
                    continue;
                }
                Customer c = Q.front(); Q.pop();
                assign_to_window(w, c, current_time);
                made_assign = true;
            }

            if (made_assign) {
                progressed = true;
            }
            else {
                break;
            }
        }

        if (!progressed) {
            int next_time = INT32_MAX;
            if (idx < N) next_time = min(next_time, all[idx].arrive);
            for (int w = 0; w < K; ++w) {
                if (end_time[w] > current_time) next_time = min(next_time, end_time[w]);
            }
            if (next_time == INT32_MAX) break;
            current_time = next_time;
        }
    }

    cout << fixed << setprecision(1)
        << (double)total_wait / N << " "
        << max_wait << " "
        << last_finish << endl;

    for (int j = 0; j < K; ++j) {
        if (j) cout << " ";
        cout << cnt[j];
    }
    cout << endl;

    return 0;
}
