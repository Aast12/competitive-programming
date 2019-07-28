#include <iostream>

using namespace std;

int main() {
    int n, t;
    string s;
    cin >> n >> s >> t;
    int lett[27][n];

    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) lett[i][0] = 0;
            if (s[j] - 'a' == i) {
                if (j == 0) lett[i][0]++;
                else lett[i][j] = lett[i][j - 1] + 1;
                continue;
            }
            lett[i][j] = lett[i][j - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 27; j++) {
            cout << char(j + 'a') << " " << lett[j][i] << " ";
        }
        cout << endl;
    }

    while (t--) {
        string name;
        cin >> name;
        
        bool fin = false;
        int letters[27], l_count = 0, t_letters = name.size();
        for (int i = 0; i < 27; i++) letters[i] = 0;
        for (auto &c : name) letters[c - 'a']++;
        if (t_letters == n) {
            cout << n;
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (letters[s[i] - 'a'] > 0) {
                l_count++;
                letters[s[i] - 'a']--;
            }
            if (l_count == t_letters) {
                cout << i + 1 << endl;
                fin = true;
                break;
            }
        }
    }
}