#include <iostream>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0, ch_i = 0; i < n; i++, ch_i++) {
            ch_i %= 26;
            cout << char('a' + ch_i);
        }
        cout << endl;
    }
 
}