#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string board[n];
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int moves[5][2] = {{0, 0}, {1, 0}, {2, 0}, {1, -1}, {1, 1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '#') {
                for (int k = 0; k < 5; k++) {
                    int ni = moves[k][0] + i;
                    int nj = moves[k][1] + j;
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n || board[ni][nj] != '#') {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
                for (int k = 0; k < 5; k++) {
                    int ni = moves[k][0] + i;
                    int nj = moves[k][1] + j;
                    board[ni][nj] = '.';
                }
            }
        }   
    }

    cout << "YES" << endl;
}