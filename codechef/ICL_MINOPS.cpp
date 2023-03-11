#include <iostream>
#include <vector>

using namespace std;

inline char succesor(char ch) { return ((ch - 'a' + 1) % ('z' - 'a'  + 1)) + 'a'; }

inline char predecesor(char ch) { return ((ch - 'a' - 1) % ('z' - 'a' + 1)) + 'a'; }

int main() {
    int t, n;
    string s;
    cin >> t;

    while (t--) {
        cin >> n >> s;
        vector<bool> check(n, 0);
        int min_count = 10e6;
        for (int st = 0; st < n; st++) {
            if (check[st]) continue;
            int i, count = 0;
            check[st] = 1;

            char next = s[st];
            for (int i = st - 1; i >= 0; i--) {
                if (s[i] != predecesor(next)) count++;
                next = predecesor(next);
            }

            char prev = s[st];
            for (int i = st + 1; i < n; i++) {
                if (s[i] == succesor(prev)) {
                    // cout << "DIFF " << (prev - 'a' + 1) << endl;
                    // cout << "MOD " << ((prev - 'a' + 1) % ('z' - 'a')) << endl;
                    // cout << "EQ " << char((prev - 'a' + 1) % ('z' - 'a') + 'a') << endl;
                    // cout << s[i] << " SUCCESS " << prev << endl;
                    check[i] = 1;
                }
                else
                    count++;
                prev = succesor(prev);
            }

            // cout << count << " FROM " << st << endl;
            min_count = min(min_count, count);
        }

        cout << min_count << endl;
    }
}