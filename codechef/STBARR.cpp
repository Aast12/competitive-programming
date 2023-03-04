#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> seq(n);

        bool all_equal = true;
        int max_i = 0;
        for (int i = 0; i < n; i++) {
            cin >> seq[i];
            if (i != 0 && all_equal && seq[i] != seq[i - 1]) all_equal = false;
            if (seq[i] >= seq[max_i]) max_i = i;
        }

        if (all_equal) {
            cout << 0 << endl;
            continue;
        }

        if (max_i == n - 1) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}