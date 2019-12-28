// OK
#include <iostream>

using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << k * (n / k) + ((n % k == 0) ? 0 : min(k / 2, n % k)) << endl;
    }
}