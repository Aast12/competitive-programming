#include <iostream>
using namespace std;

int main() {
    int t, a, b, n;
    cin >> t;

    while (t--) {
        cin >> a >> b >> n;
        if ((b - a) % (n + 1) != 0) {
            cout << "NO" << endl;
            continue;
        }

        int d = (b - a) / (n + 1);

        if (a + (n + 1) * d != b) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
