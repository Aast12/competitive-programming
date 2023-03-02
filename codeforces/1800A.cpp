#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, n, next;
    string s, meow = "meow";
    cin >> t;

    while (t--) {
        cin >> n >> s;
        next = 0;
        char curr = tolower(s[0]), prev = curr;
        bool pos = curr == meow[0];

        for (int i = 1; i < n && pos; i++) {
            curr = tolower(s[i]);
            if (curr != prev) next++;
            if (next > 3 || curr != meow[next]) {
                pos = false;
                break;
            }
            prev = curr;
        }

        pos = pos && (next == 3);

        cout << (pos ? "YES" : "NO") << endl;
    }
}