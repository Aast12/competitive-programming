#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, x, total_sum;
    cin >> t;

    while (t--) {
        cin >> n >> x;

        vector<int> deposit(n);
        total_sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> deposit[i];
            total_sum += deposit[i];
            deposit[i] *= -1;
        }

        if (total_sum < x) {
            cout << -1 << endl;
            continue;
        }

        sort(deposit.begin(), deposit.end());
        int count = 0, sum = 0;
        for (int d : deposit) {
            if (sum >= x) break;
            sum -= d;
            count++;
        }

        cout << count << endl;
    }
}