#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, k;
    string s;
    cin >> t;
    while (t--) {
        vector<int> lower(26, 0), upper(26, 0);
        cin >> n >> k >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                upper[s[i] - 'A']++;
            } else {
                lower[s[i] - 'a']++;
            }
        }
        
        int added = 0, spare, total = 0;
        for (int i = 0; i < 26; i++) {
            spare = max(lower[i], upper[i]) - min(lower[i], upper[i]);
            total += min(lower[i], upper[i]);
            // cout << "add total " << char('a' + i) << " " << min(lower[i], upper[i]) << endl;
            // cout << "added " << spare / 2 << endl;
            added += spare / 2;
        }

        cout << total + min(k, added) << endl;
    }
}