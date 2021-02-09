// TLE
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef int ull;

struct State {
    int a_sum, b_sum, step;
    State() {}
    State(int a, int b, int s) : a_sum(a), b_sum(b), step(s) {}
};

void fastscan(ull &x) {
    char ch;
    bool f = 0;
    ull a = 0;
    while (!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')))
        ;
    if (ch != '-')
        a *= 10, a += ch - '0';
    else
        f = 1;
    while (((ch = getchar()) >= '0') && (ch <= '9')) a *= 10, a += ch - '0';
    if (f) a = -a;
    x = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, k, h_i, a_sum, b_sum, used;
    fastscan(t);

    while (t--) {
        a_sum = b_sum = used = 0;
        fastscan(n);
        fastscan(k);

        vector<int> heights(n), sums(n);
        // vector<int> min_gaps(n, -1);

        for (int i = 0; i < n; i++) {
            fastscan(h_i);
            // cin >> heights[i];
            heights[i] = h_i;
        }

        sort(heights.begin(), heights.end(), greater<int>());

        sums[0] = heights[0];
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i - 1] + heights[i];
        }

        int ideal_steps;
        auto low = lower_bound(sums.begin() + 1, sums.end(), 2 * k);

        if (low == sums.end()) {
            cout << -1 << endl;
            continue;
        } else {
            ideal_steps = low - sums.begin() + 1;
            auto it_ideal = lower_bound(sums.begin(), sums.begin() + ideal_steps, k);
            int ideal = it_ideal - sums.begin();
            if (sums[ideal] > k && sums[ideal_steps - 1] - sums[ideal] > k) {
                cout << ideal_steps << endl;
                continue;
            }
        }

        stack<State> bfsq;

        bfsq.push(State(0, 0, 0));

        bool found = false;

        int min_steps = -1;

        while (!bfsq.empty()) {
            State curr = bfsq.top();
            bfsq.pop();

            if (min_steps == ideal_steps) break;
            if (curr.a_sum >= k && curr.b_sum >= k) {
                min_steps = min_steps == -1 ? curr.step : min(curr.step, min_steps);
            }

            int min_sum = (2 * k - min(k, curr.a_sum) - min(k, curr.b_sum));

            // if (min_gaps[curr.step] == -1) min_gaps[curr.step] = min_sum;
            // else if (min_gaps[curr.step] < min_sum) continue;

            auto it_extra_steps = lower_bound(sums.begin() + curr.step, sums.end(), min_sum + (curr.step > 0 ? sums[curr.step - 1] : 0));
            if (it_extra_steps == sums.end()) continue;

            // int extra_steps = min_sum / heights[curr.step] + (min_sum % heights[curr.step] != 0);
            int expected_steps = it_extra_steps - sums.begin() + 1;

            // cout << "LOOK " << min_sum << " - > " <<min_sum + (curr.step > 0 ? sums[curr.step - 1] : 0) << endl;
            // cout << curr.step << " " << curr.a_sum << " " << curr.b_sum << " -> " << expected_steps << endl;

            if (min_steps != -1 && (curr.step >= min_steps || expected_steps >= min_steps)) continue;

            if (curr.step > n) continue;
            if (curr.step != 0 && (curr.a_sum + sums[n - 1] - sums[curr.step - 1] < k || curr.b_sum + sums[n - 1] - sums[curr.step - 1] < k)) {
                continue;
            }

            if (curr.a_sum < k) bfsq.push(State(curr.a_sum + heights[curr.step], curr.b_sum, curr.step + 1));
            if (curr.b_sum < k) bfsq.push(State(curr.a_sum, curr.b_sum + heights[curr.step], curr.step + 1));
        }

        cout << min_steps << endl;
    }
}