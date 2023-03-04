#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c, k;
    int neighbors[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    while (cin >> n >> r >> c >> k) {
        if (n + r + c + k == 0) break;

        int grid[r][c], next[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
                next[i][j] = grid[i][j];
            }
        }

        while (k--) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    for (int adj = 0; adj < 4; adj++) {
                        int ni = i + neighbors[adj][0],
                            nj = j + neighbors[adj][1];

                        if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                            if (grid[ni][nj] == (grid[i][j] + 1) % n) {
                                next[ni][nj] = grid[i][j];
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    grid[i][j] = next[i][j];
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << grid[i][j] << (j == c - 1 ? "" : " ");
            }
            cout << endl;
        }
    }
}