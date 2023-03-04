#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    string s;
    cin >> t;

    while (t--) {
        vector<short> counts('z' + 1, 0);
        cin >> s;

        for (auto &ch : s) {
            counts[ch]++;
        }

        for (int i = 0; i < counts.size(); i++) {
            while (counts[i] != 0) {
                cout << char(i);
                counts[i]--;
            }
        }

        cout << endl;
    }
}