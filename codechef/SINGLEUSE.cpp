#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int t, x, y, h;
    cin >> t;

    while (t--) {
        cin >> h >> x >> y;
        cout << ceil(float(h - y) / x) + 1 << endl;
    }
}