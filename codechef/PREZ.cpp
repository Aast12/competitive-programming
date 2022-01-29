#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, k, prev, curr;
    string s;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        cin >> s;

        vector<int> acc(n, 0);

        for (int i = 0; i < n; i++) {
            curr = (10 - (s[i] - '0')) % 10;
            if (i != 0) {
                acc[i] = acc[i - 1]; 
                if (curr <= prev) {
                    acc[i] += prev - curr;
                } else {
                    acc[i] += 10 - curr + prev;
                }
            }
            if (acc[i] + curr > k) {
                cout << i << endl;
                break;
            }
            if (i == n - 1) {
                cout << n << endl;
            }
            prev = curr;
        }
    }
}