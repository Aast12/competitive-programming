#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> matrix;

matrix rotate_mat(matrix &mat) {
    matrix rotated(mat.size(), vi(mat[0].size()));

    int cols = mat[0].size(), rows = mat.size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rotated[rows - j - 1][i] = mat[i][j];
        }
    }

    return rotated;
}

void swipe(matrix &mat) {
    int cols = mat[0].size(), rows = mat.size();
    for (int i = 0; i < rows; i++) {
        int prev = -1, prev_idx = 0, zeros = 0;
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 0) {
                zeros++;
            } else if (prev == -1) {
                prev = mat[i][j];
                prev_idx = j;
            } else if (mat[i][j] == prev) {
                mat[i][prev_idx] = 0;
                zeros++;
                mat[i][j] = mat[i][j] * 2;
                prev = -1;
            } else {
                prev = mat[i][j];
                prev_idx = j;
            }
        }

        int idx = 0;
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                mat[i][idx] = mat[i][j];
                idx++;
            }
        }

        for (int j = 0; j < zeros; j++) mat[i][cols - j - 1] = 0;
    }
}

int main() {
    int mov;
    matrix mat(4, vi(4));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mat[i][j];
        }
    }

    cin >> mov;
    for (int r = 0; r < mov; r++) mat = rotate_mat(mat);

    swipe(mat);

    for (int r = 0; r < (4 - mov) % 4; r++) mat = rotate_mat(mat);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}