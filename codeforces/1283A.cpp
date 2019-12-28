// OK
#include <iostream>

using namespace std;

int main() {
    int t, h, m;
    cin >> t;
    while (t--) {
        cin >> h >> m;
        cout << (60 - m) + (24 - h - 1) * 60 << endl;
    }
}