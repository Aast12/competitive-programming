#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef vector<int> vi;
typedef vector<vi> raw_matrix;

struct Matrix {
    raw_matrix mat;
    int rows, cols;

    Matrix(vector<vi> values)
        : mat(values), rows(values.size()), cols(values[0].size()) {}

    static Matrix identity_matrix(int n) {
        vector<vi> values(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const {
        int n = rows, m = other.cols;
        vector<vi> result(rows, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < cols; k++) {
                    result[i][j] =
                        (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) %
                        MOD;
                }
            }
        return Matrix(result);
    }

    vi operator[](const int &index) const {
        return mat[index];
    }
};

Matrix fast_exponentiation(Matrix m, int power) {
    Matrix result = Matrix::identity_matrix(m.rows);

    while (power) {
        if (power & 1) result = result * m;
        m = m * m;
        power >>= 1;
    }

    return result;
}

int main() {
    int n, m, k, a, b;

    cin >> n >> m >> k;

    raw_matrix mat(n, vi(n));
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    Matrix mat_k = fast_exponentiation(mat, k);
    int paths = 0;
    for (int i = 0; i < mat_k.cols; i++) {
        paths += mat_k[0][i];
        paths %= MOD;
    }

    cout << paths << endl;
    
}