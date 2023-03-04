#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> a(n);
        int pow_count = 0;
        int extra_count = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int cp = a[i];
            while (!(cp & 1) && cp > 0) {
                pow_count++;
                cp >>= 1;
            }
        }
        
        int max_pow = floor(log2(n));
        int acc = 0;

        while (pow_count < n && max_pow > 0) {
            int count = n / (1 << max_pow) - acc;
            if (pow_count + count * max_pow >= n) {
                while(pow_count < n) {
                    pow_count += max_pow;
                    acc++;
                }
                break;
            }
            pow_count += count * max_pow;
            acc += count;
            max_pow--;
        }
        if (pow_count >= n) cout << acc << endl;
        else cout << -1 << endl;
        
        
    }
}