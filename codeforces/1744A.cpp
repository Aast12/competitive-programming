#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int t, n;
    string s;
    cin >> t;

    while (t--) {
        cin >> n;
        bool pos = true;
        vector<int> a(n);
        map<int, char> mapping;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (mapping.find(a[i]) != mapping.end()) {
                if (mapping[a[i]] != s[i]) {
                    pos = false;
                    break;
                }
            } else {
                mapping[a[i]] = s[i];
            }
        }

        cout << (pos ? "YES" : "NO") << endl;
    }
}