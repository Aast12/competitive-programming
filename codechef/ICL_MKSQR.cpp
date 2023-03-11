#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ull a[4], minv = 10e9 + 1;
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
            minv = min(a[i], minv);
        }

        ull waste = 0;
        for (int i = 0; i < 4; i++) {
            waste += a[i] -  minv;
        }

        cout << waste << endl;
    }
}