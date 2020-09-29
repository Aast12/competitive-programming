#include <iostream>

using namespace std;

int main() {
    int n, l, r, l1 = 0, r1 = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        l1 += l;
        r1 += r;
    }

    int l0 = n - l1, r0 = n - r1; 

    cout << min(min(l0 + r1, l1 + r0), min(l0 + r0, l1 + r1)) << endl;
}