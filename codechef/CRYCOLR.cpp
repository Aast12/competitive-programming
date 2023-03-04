#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        int count = 0;
        int colors[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> colors[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    colors[j][i] -= colors[i][j];
                    colors[i][i] += colors[i][j];
                    count += colors[i][j];
                }
            }
        }

        cout << count << endl;
    }
}