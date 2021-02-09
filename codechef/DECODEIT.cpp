#include <iostream>

using namespace std;

char decodeChar(const string& s, int start) {
    int lb = 0, ub = 15;
    for (int i = start; i < start + 4; i++) {
        if (s[i] == '0') {
            ub = (lb + ub) / 2;
        } else {
            lb = (lb + ub) / 2 + 1;
        }
    }

    return 'a' + ub;
}

string decode(const string& s) {
    string ans;
    for (int i = 0; i < s.size(); i += 4) {
        ans.push_back(decodeChar(s, i));
    }

    return ans;
}

int main() {
    int t, n;
    string s;
    cin >> t;

    while (t--) {
        cin >> n >> s;

        cout << decode(s) << endl;
    }
}