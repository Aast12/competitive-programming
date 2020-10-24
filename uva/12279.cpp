#include <iostream>

using namespace std;

int main() {
    int n, x, caseno = 0, zeros;

    while (cin >> n) {
        if (n == 0) break;
        caseno++;
        zeros = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x == 0) zeros++;
        }

        cout << "Case " << caseno << ": " << n - 2 * zeros << endl;
    }
}