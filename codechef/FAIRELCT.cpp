#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long t, n, m, a_sum, b_sum, pack;
    cin >> t;

    while (t--) {
        a_sum = b_sum = 0;
        cin >> n >> m;

        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            cin >> pack;
            a.push_back(pack);
            a_sum += pack;
        }
        for (int i = 0; i < m; i++) {
            cin >> pack;
            b.push_back(pack);
            b_sum += pack;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int highest = m - 1, swaps = 0;
        for (int i = 0; i < n && a_sum <= b_sum && highest >= 0; i++) {
            a_sum += b[highest] - a[i];
            b_sum += a[i] - b[highest--];
            swaps++;
        }

        cout << (a_sum > b_sum ? swaps : -1) << endl;
    }
}