#include <iostream>
#define MOD 1000000007

typedef unsigned long long ull;

using namespace std;

int main() {
    ull t, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        ull a1 = (n + 2) % MOD;
        ull a2 = (n + 1) % MOD;
        ull a3 = (k + 1) % MOD;
        ull a = (((a1 * a2) % MOD) * a3) % MOD;
        cout << (a / 2) % MOD << endl;
    }
    
}