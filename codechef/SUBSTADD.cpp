#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, x, y, diff;
    bool pos;
    cin >> t;

    while (t--) {
        cin >> n >> x >> y;

        vector<int> A(n), B(n);
        pos = 1;

        for (int i = 0; i < n; i++)
            cin >> A[i];
        
        for (int i = 0; i < n; i++) {
            cin >> B[i];
            diff = B[i] - A[i];
            if (pos && (diff != x && diff != y)) {
                pos = 0;
            }
        }

        cout << (pos ? "Yes\n" : "No\n");
    }
}