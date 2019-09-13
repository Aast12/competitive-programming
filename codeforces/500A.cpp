#include <iostream>

using namespace std;

int main() {
    int n, t, curr = 0, i = 0;
    bool found = false;
    cin >> n >> t;
    t--; n--;

    int cells[n];
    for (int i = 0; i < n; i++) {
        cin >> cells[i];
    }

    while (true) {  
        if (curr > n) break;
        if (curr == t) {
            found = true;
            break;
        }
        curr = curr + cells[curr];
    }

    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;

}