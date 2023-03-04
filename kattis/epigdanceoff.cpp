#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string grid[n];
    for (int i = 0; i < n; i++) cin >> grid[i];

    bool is_blank;
    int frame_count = 1;
    for (int i = 0; i < m; i++) {
        is_blank = true;
        for (int j = 0; j < n; j++) {
            if (grid[j][i] == '$'){
                is_blank = false;
                break;
            }
        }   
        frame_count += is_blank;
    }

    cout << frame_count << endl;
}