#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    const int mat_size = n * 2 + 1;
    int mat[mat_size][mat_size];

    for (int i = 0; i < mat_size; i++)
        for (int j = 0; j < mat_size; j++)
            mat[i][j] = -1;

    for (int k = 0; k < n; k++) {
        for (int i = k; i <= n; i++) {
            mat[i][i + n - k] = k;
            mat[i + n - k][i] = k;
        }
        for (int i = k; i <= n; i++) {
            mat[i][i + n + k - 2 * i] = k;
            mat[i + n - k][i + 2 * n - 2 * i] = k;
        }
    }
    
    for (int i = 0; i < mat_size; i++) {
        for (int j = 0; j < mat_size; j++) {
            if (j >= n && mat[i][j] == 0) {
                cout << mat[i][j];
                break;
            }
            if (i == n && j == n) cout << n << " ";
            else if (mat[i][j] == -1) cout << "  ";
            else cout << mat[i][j] << " ";
        }   
        cout << endl;
    }
}