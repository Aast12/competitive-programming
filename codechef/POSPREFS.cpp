#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        vector<int> ans;

        int positives = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 && positives < k) {
                ans.push_back(i);
                positives++;
            } else {
                ans.push_back(-(i));
            }
        }

        if (positives < k) {
            for (int i = n - 1; i >= 0 && positives < k; i--) {
                if (ans[i] < 0) {
                    ans[i] = i + 1;
                    positives++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? "\n" : " ");
        }
    }
}