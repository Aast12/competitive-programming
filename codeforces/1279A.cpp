#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lli;

int main() {
    lli t, c[3];
    cin >> t;
    while (t--) {
        cin >> c[0] >> c[1] >> c[2];
        sort(c, c + 3);
        lli av = c[2] + c[1] + 1;
        if (c[0] >= c[2] - c[1] - 1 && c[0] <= av) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}