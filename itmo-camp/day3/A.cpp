#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector< vector<int> > map(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (i == 0 && j != 0)
                map[i][j] += map[i][j - 1];
            else if (j == 0 && i != 0)
                map[i][j] += map[i - 1][j];
            else if (i != 0 && j != 0)
                map[i][j] += min(map[i - 1][j], map[i][j - 1]);
        }
    }

    cout << map[n - 1][m - 1] << endl;
}