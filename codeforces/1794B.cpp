#include <iostream>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                a[i]++;
            }

            if (i > 0 && a[i] % a[i - 1] == 0) {
                a[i]++;
            }
        }

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}