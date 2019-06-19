#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull m_size = 1000000;
ull counts[1000000];

ull find_count(ull n) {
    if (n < m_size && counts[n] != 0) return counts[n];
    
    ull count = 1 + find_count((n % 2) ? (3 * n + 1) : (n / 2));

    if (n < m_size) counts[n] = count;    

    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ull i, j;
    counts[0] = 1;
    counts[1] = 1;
    while (cin >> i >> j) {
        ull max_c = 0, tmp;
        for (ull a = min(i, j); a <= max(i, j); a++) {
            tmp = find_count(a);
            if (tmp > max_c) {
                max_c = tmp;
            }
        }
        cout << i << " " << j << " " << max_c << endl;
    }

 }