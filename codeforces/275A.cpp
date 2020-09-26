#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<bool>> states(3, vector<bool>(3, 1));
    int sides[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int toggles;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> toggles;
            states[i][j] = (toggles % 2) ? !states[i][j] : states[i][j];
            for (int s = 0; s < 4; s++) {
                int ni = i + sides[s][0], nj = j + sides[s][1];
                if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3) {
                    states[ni][nj] = (toggles % 2) ? !states[ni][nj] : states[ni][nj];
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << states[i][j];
        }
        cout << endl;
    }
}