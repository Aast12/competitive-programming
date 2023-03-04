#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    while (n--) {
        cin >> s;
        sort(s.begin(), s.end());

        string t(s);
        int len = s.size();
        for (int i = 0, j = 0; i < len; i += 2, j++) {
            if (j == len - j - 1) {
                t[j] = s[i];
            } else {
                t[j] = max(s[i], s[i + 1]);
                t[len - j - 1] = min(s[i], s[i + 1]);
            }
        }

        cout << t << endl;
    }
}