#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int c_count = 0, a_count = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'c') c_count++;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'b')
            ans += (long long)c_count * a_count;
        else if (s[i] == 'a')
            a_count++;
        else if (s[i] == 'c')
            c_count--;
    }

    cout << ans << endl;
}