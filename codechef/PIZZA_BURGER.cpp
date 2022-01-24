#include <iostream>

using namespace std;

int main() {
    int t, x, y, z;
    cin >> t;

    while (t--) {
        cin >> x >> y >> z;

        if (x < y && x < z) {
            cout << "NOTHING\n";
            continue;
        }

        if (x >= y) cout << "PIZZA\n";
        else cout << "BURGER\n";
    }
}