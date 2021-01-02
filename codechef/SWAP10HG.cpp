//PENDING

#include <iostream>

using namespace std;

int main() {
    int t, n;
    string s, p;
    cin >> t;

    while (t--) {
        int s_count[] = {0, 0}, p_count[] = {0, 0};
        cin >> n >> s >> p;

        for (int i = 0; i < n; i++) {
            s_count[0] += s[i] == '0';
            s_count[1] += s[i] == '1';

            p_count[0] += p[i] == '0';
            p_count[1] += p[i] == '1';
        }

        if (s_count[0] == p_count[0] && s_count[1] == p_count[1])
            cout << "Yes";
        else
            cout << "No";

        cout << endl;
    }
}