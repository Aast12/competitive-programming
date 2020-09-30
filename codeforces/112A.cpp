#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); i++) {
        char c1 = (s1[i] < 'a') ? s1[i] + ('a' - 'A') : s1[i];
        char c2 = (s2[i] < 'a') ? s2[i] + ('a' - 'A') : s2[i];
        if (c1 < c2) {
            cout << -1 << endl;
            break;
        }
        else if (c1 > c2) {
            cout << 1 << endl;
            break;
        }
        else if (i == s1.size() - 1) {
            cout << 0 << endl;
        }
    }
}