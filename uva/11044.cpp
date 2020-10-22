#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, w, h;
    cin >> n;

    while (n--) {
        cin >> w >> h;
        cout << long(ceil((w - 2) / 3.f)) * long(ceil((h - 2) / 3.f)) << endl;
    }
}