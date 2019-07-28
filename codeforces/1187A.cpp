#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll T;
    cin >> T;

    while (T--) {
        ll n, t, s;
        cin >> n >> s >> t;
        if (s + t == n) {
            cout << max(s, t) + 1 << endl;
        }
        else if (s + t > n) {
            cout << n - min(s, t) + 1 << endl;
        }
        
    }
}