#include <iostream>

using namespace std;

int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    int image[h][w], kernel[n][m];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> image[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> kernel[i][j];

    for (int i = 0; i <= h - n; i++) {
        for (int j = 0; j <= w - m; j++) {
            int dot = 0;
            for (int ki = n - 1, i_offset = 0; ki >= 0; ki--, i_offset++) {
                for (int kj = m - 1, j_offset = 0; kj >= 0; kj--, j_offset++) {
                    dot += image[i + i_offset][j + j_offset] * kernel[ki][kj];
                }
            }

            cout << dot << (j == w - m ? "\n" : " ");
        }
    }
}