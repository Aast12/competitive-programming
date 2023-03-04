#include <iostream>

using namespace std;

int counts[51];

int main() {
    int n, ai, max_no = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ai;
        counts[ai]++;
        max_no = max(ai, max_no);
    }

    for (int i = max_no; i > 0; i--) {
        if (counts[i] == i) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}