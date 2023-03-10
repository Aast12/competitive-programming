#include <iostream>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        int happy_count = 0;
        int a[n], b[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        for (int i = 0; i < n; i++) {
            if (!(a[i] > 2 * b[i] || b[i] > 2 * a[i])) {
                happy_count++;
            }
        } 

        cout << happy_count << endl;
    }
}