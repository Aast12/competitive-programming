#include <iostream>

using namespace std;

int main() {
    int t, n, x;
    cin >> t;

    while (t--) {
        cin >> n;
        int min = 100, max = -1;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x > max) max = x;
            if (x < min) min = x;
        } 

        cout << (max - min) * 2 << endl;
    }
}