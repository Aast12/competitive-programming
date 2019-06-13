#include <iostream>
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main() {
    io;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1 || n == 2) {
            cout << n << endl;
        } else {
            cout << (n - 2) * 3 + 1 << endl;
        }
    }
}