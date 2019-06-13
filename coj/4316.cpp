#include <iostream>
#include <map>
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main() {
    io;
    long long n, s;
    int aux;
    while(cin >> n >> s) {
        map <long long, int> ans;
        long long sums[n];
        for (int i = 0; i < n; i++) {
            cin >> aux;
            sums[i] = aux;
            if (i != 0) sums[i] += sums[i - 1];
            ans[sums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if (sums[i] < s) continue;
            if (sums[i] == s) {
                cout << 1 << " " << i + 1 << endl;
                break;
            } else {
                if (ans.find(sums[i] - s) != ans.end()) {
                    cout << ans[sums[i] - s] + 2 << " " << i + 1 << endl;
                    break;
                }
            }
        }

    }
}