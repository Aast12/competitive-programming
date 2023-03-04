#include <iostream>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        if (n % 2 == 1) {
            cout << -1 << endl;
            continue;
        }

        int half = n / 2;

        for (int i = 0; i < half; i++) cout << 1;
        for (int i = 0; i < half; i++) cout << 0;

        cout << endl;
    }
}