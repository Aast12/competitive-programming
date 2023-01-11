#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, q, query, x;
    cin >> t;

    while (t--) {
        cin >> n >> q;

        vector<int> a(n);
        int odd_count = 0, even_count = 0;
        long long total_sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] & 1)
                odd_count++;
            else
                even_count++;

            total_sum += a[i];
        }

        while (q--) {
            cin >> query >> x;

            if (query == 0) {
                total_sum += x * even_count;
                if (x & 1) {
                    odd_count += even_count;
                    even_count = 0;
                }
            } else {
                total_sum += x * odd_count;
                if (x & 1) {
                    even_count += odd_count;
                    odd_count = 0;
                }
            }

            cout << total_sum << endl;
        }
    }
}