#include <iostream>
#include <vector>

using namespace std;

typedef pair<string, string> pss;
int main() {
    int t, n;
    string s;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<pss> fixes(n, {"", ""});
        for (int i = 0; i < 2 * n - 2; i++) {
            cin >> s;
            if (fixes[s.size()].first.empty()) {
                fixes[s.size()].first = s;
            } else {
                fixes[s.size()].second = s;
            }
            // fixes[s.size()].second = fixes[s.size()].first;
            // fixes[s.size()].second = s;
        }

        bool pos = true;
        for (int i = 1; i < n && pos; i++) {
            string left = fixes[i].first, right = fixes[i].second;
            // cout << "CMP " << left << " " << right << endl;
            for (int j = 0; j < i; j++) {
                if (left[j] != right[i - j - 1]) {
                    pos = false;
                    break;
                }
            }
        }

        cout << (pos ? "YES" : "NO") << endl;
    }
}