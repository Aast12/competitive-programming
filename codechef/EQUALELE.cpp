#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t, n, a;
    cin >> t;

    while (t--) {
        cin >> n;
        unordered_map<int, int> freqs;
        int max_freq = 1;
        for (int i = 0; i < n; i++) {
            cin >> a;
            auto a_freq = freqs.find(a);
            if (a_freq != freqs.end()) {
                a_freq->second++;
                max_freq = max(max_freq, a_freq->second);
            } else {
                freqs[a] = 1;
            }
        }

        cout << (n - max_freq) << endl;
    }
}