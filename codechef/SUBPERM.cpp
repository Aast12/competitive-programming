#include <iostream>

using namespace std;

int main() {
    int t, n, k, min_k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        min_k = min(n, 2);

        if (k < min_k) {
            cout << "-1\n";
            continue;
        }

        for (int i = 0; i < k - 1; i++)
            cout << i + 1 << " ";

        for (int i = k - 1, j = n; i < n; i++, j--)
            cout << j << " ";

        cout << endl;
    }
}