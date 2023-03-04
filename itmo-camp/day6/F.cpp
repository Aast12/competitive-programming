#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<long long> vll;

int main() {
    int t, r, m, a, b;
    string s;
    cin >> t >> r >> s;

    int n = s.size();
    vll hash(n, 0);
    hash[0] = s[0] % r;
    for (int i = 1; i < n; i++) hash[i] = (hash[i - 1] * t + s[i]);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        long long right = hash[b];
        long long left = a == 0 ? 0 : hash[a - 1];
        left *= pow(t, b - a + 1);
        cout << (right - left) % r << endl;
    }
}
