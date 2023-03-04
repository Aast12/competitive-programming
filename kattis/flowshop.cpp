#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ptime[n][m], endtime[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> ptime[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = (i == 0) ? 0 : endtime[i - 1][j];
            int left = (j == 0) ? 0 : endtime[i][j - 1];

            endtime[i][j] = max(up, left) + ptime[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << endtime[i][m - 1] << (i == n - 1 ? "\n" : " ");
    }
}