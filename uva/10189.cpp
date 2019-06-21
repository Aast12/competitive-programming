#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n, m, test = 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        if (test > 1) cout << endl;

        char in_mat[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> in_mat[i][j];
            }
        }
        
        cout << "Field #" <<  test++ << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (in_mat[i][j] == '*') {
                    cout << '*';
                    continue;
                }
                int adj = 0;
                if (i - 1 >= 0 && in_mat[i - 1][j] == '*') adj++;
                if (i + 1 <  n && in_mat[i + 1][j] == '*') adj++;
                if (j - 1 >= 0 && in_mat[i][j - 1] == '*') adj++;
                if (j + 1 <  m && in_mat[i][j + 1] == '*') adj++;

                if (i - 1 >= 0 && j - 1 >= 0 && in_mat[i - 1][j - 1] == '*') adj++;
                if (i + 1 <  n && j + 1 <  m && in_mat[i + 1][j + 1] == '*') adj++;
                if (i - 1 >= 0 && j + 1 <  m && in_mat[i - 1][j + 1] == '*') adj++;
                if (i + 1 <  n && j - 1 >= 0 && in_mat[i + 1][j - 1] == '*') adj++;

                cout << adj;
            }
            cout << endl;
        }
    }
}