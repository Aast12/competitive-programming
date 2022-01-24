#include <iostream>

using namespace std;

int main() {
    int t, n, a;
    cin >> t;

    while (t--) {
        cin >> n >> a;
        cout << min(n - a, a) << endl;
    }
}