#include <iostream>

using namespace std;

int letter_count[27];

int main() {
    string s1, s2, s;
    cin >> s1 >> s2 >> s;

    for (int i = 0; i < s1.size(); i++) {
        letter_count[s1[i] - 'A']++;
    }
    for (int i = 0; i < s2.size(); i++) {
        letter_count[s2[i] - 'A']++;
    }

    bool permutable = true;
    for (int i = 0; i < s.size(); i++) {
        letter_count[s[i] - 'A']--;
    }

    for (int i = 0; i < 27; i++) {
        if (letter_count[i] != 0) {
            permutable = false;
            break;
        }
    }

    cout << (permutable ? "YES" : "NO") << endl;
}