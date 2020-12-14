#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;
    string a, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> a >> b;
        vector<int> moves;
        for (int j = n - 1; j >= 0; j--) {
            if (a[j] != b[j]) {
                moves.push_back(j + 1);
                moves.push_back(1);
                moves.push_back(j + 1);
            }
        }
        cout << moves.size();
        for (auto &m: moves) {
            cout << " " << m;
        }
        cout << endl;
    }
}