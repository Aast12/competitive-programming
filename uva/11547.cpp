#include <iostream>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        cout << abs((315 * n + 36962) / 10) % 10 << endl;
    }
}