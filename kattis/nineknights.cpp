#include <iostream>

using namespace std;

int main() {
    string board[5];
    int moves[8][2] = {
        {2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2},
    };

    int n = 5;
    for (int i = 0; i < n; i++) 
        cin >> board[i];

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'k') {
                count++;
                for (int m = 0; m < 8; m++) {
                    int mi = moves[m][0] + i, mj = moves[m][1] + j;
                    if (mi >= 0 && mi < n && mj >= 0 && mj < n &&
                        board[mi][mj] == 'k') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    if (count != 9) cout << "invalid" << endl;
    else cout << "valid" << endl;
}