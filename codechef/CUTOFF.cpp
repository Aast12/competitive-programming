#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n, x;
    cin >> t;

    while (t--) {
        cin >> n >> x;

        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        sort(A.begin(), A.end());

        cout << A[n - x] - 1 << endl;
    }
}