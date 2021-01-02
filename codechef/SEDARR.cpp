#include <iostream>

using namespace std;

int main() {
    int t, n, k;

    cin >> t;

    while (t--) {
        cin >> n >> k;
        unsigned long long a[n], sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        cout << (sum % k ? 1 : 0) << endl;
    }
}