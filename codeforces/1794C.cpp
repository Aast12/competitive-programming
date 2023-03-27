#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long double ld;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        int a[n];
        priority_queue<int, vector<int>, greater<int> > chosen;
        ld prev_m = 1, curr_m = 1, replace, add;
        int curr_len = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0) {
                cout << 1 << " ";
                curr_m = prev_m * (a[i] / ld(i + 1));
                chosen.push(a[i]);
            } else {
                replace = prev_m * (a[i] / chosen.top());
                add = prev_m * (a[i] / ld(i + 1));
                if (prev_m >= replace && prev_m >= add) {
                    if (prev_m == add) {
                        curr_len++;
                        chosen.push(a[i]);
                    }
                    cout << curr_len << " ";
                } else if (replace > add) {
                    chosen.pop();
                    chosen.push(a[i]);
                    prev_m = replace;
                    cout << curr_len << " ";
                } else {
                    curr_len++;
                    chosen.push(a[i]);
                    prev_m = replace;
                    cout << curr_len << " ";
                }
                // curr_m = prev_m * (a[i] / ld(i + 1));
                // if ()
            }
        }
        cout << endl;
    }
}