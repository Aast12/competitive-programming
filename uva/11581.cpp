#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> matrix;

const int neighbors[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

matrix next_matrix(matrix& curr) {
    matrix next(3, vi(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int n = 0; n < 4; n++) {
                int r = neighbors[n][0] + i, c = neighbors[n][1] + j;

                if (r >= 0 && r < 3 && c >= 0 && c < 3) sum += curr[r][c];
            }

            next[i][j] = sum % 2;
        }
    }

    return next;
}

int hash_matrix(matrix& mat) {
    int hash_int = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == 1) {
                hash_int ^= 1 << (i * 3 + j + 1);
            }
        }
    }

    return hash_int;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        matrix mat(3, vi(3));
        string row;
        for (int i = 0; i < 3; i++) {
            cin >> row;
            for (int j = 0; j < 3; j++) {
                mat[i][j] = row[j] - '0';
            }
        }

        map<int, int> patterns;

        int curr_index = 0, curr_hash = hash_matrix(mat);
        matrix next = mat;
        while (patterns.find(curr_hash) == patterns.end()) {
            patterns[curr_hash] = curr_index++;
            next = next_matrix(next);
            curr_hash = hash_matrix(next);
        }

        cout << patterns[curr_hash] - 1 << endl;
    }
}