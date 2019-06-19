#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    int len = line.size();
    int bound = floor(sqrt((float)len));
    int cols, rows, c_count = 0;
    if (bound * bound >= len) {
        cols = rows = bound;
    } else if (bound * (bound + 1) >= len) {
        rows = bound;
        cols = bound + 1;
    } else {
        cols = rows = bound + 1;
    }

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (j * cols + i < len && c_count <= len) {
                cout << line[j * cols + i];
                c_count++;
            }
        }
        if (c_count == len) break;
        cout << " ";
    }

}