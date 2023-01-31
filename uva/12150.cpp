#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;

    while (cin >> n) {
        if (n == 0) {
            break;
        }

        pii carinfo = make_pair(0, 0);
        vector<int> positions(n, -1);

        bool pos = true;
        for (int i = 0; i < n; i++) {
            cin >> carinfo.first >> carinfo.second;
            carinfo.first--;

            if (!pos) continue;

            int starting_pos = i + carinfo.second;

            if (starting_pos < 0 || starting_pos >= n ||
                positions[starting_pos] != -1) {
                pos = false;
            } else {
                positions[starting_pos] = carinfo.first;
            }
        }

        if (pos) {
            for (int i = 0; i < n; i++) {
                int pos = positions[i];
                cout << pos + 1;

                if (i == n - 1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }

        } else {
            cout << -1 << endl;
        }
    }
}