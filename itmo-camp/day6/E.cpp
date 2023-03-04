#include <iostream>
#include <vector>

using namespace std;
typedef vector<long long> vll;

int main() {
    int t, r;
    string s;
    cin >> t >> r >> s;

    int n = s.size();
    vll hashes(n, 0);
    hashes[0] = s[0] % r;
    for (int i = 1; i < n; i++)
        hashes[i] = (hashes[i - 1] * t + s[i]) % r;
    
    for (int i = 0; i < n; i++)
        cout << hashes[i] << endl;
    
}
