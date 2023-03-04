#include <iostream>
#include <vector>

using namespace std;

int nmod(int a, int mod) { return (mod + (a % mod)) % mod; }
int prod(int a, int b, int mod) { return nmod(a * b, mod); }
int c(vector<int> &b, int i, int n) { return nmod(b[i], n); }

int main() {
    int n, x, y, a0, m, z, t, b0;

    cin >> n >> x >> y >> a0;
    cin >> m >> z >> t >> b0;
    vector<int> a(n), b;
    vector<long long> sum(n, 0);
    a[0] = sum[0] = a0;

    b.push_back(b0);
    int a_mod = 1 << 16, b_mod = 1 << 30;
    long long total_sum = 0;

    for (int i = 1; i < n; i++) {
        a[i] = nmod(x * a0 + y, a_mod);
        sum[i] = sum[i - 1] + a[i];
        a0 = a[i];
    }

    for (int i = 1; i < m * 2 + 1; i++) {
        b.push_back(nmod(prod(z, b0, b_mod) + t, b_mod));
        b0 = b.back();
    }

    for (int i = 0; i < m; i++) {
        int candidates[] = {c(b, 2 * i, n), c(b, 2 * i + 1, n)};
        int left = min(candidates[0], candidates[1]);
        int right = max(candidates[0], candidates[1]);

        total_sum += sum[right] - (left == 0 ? 0 : sum[left - 1]);
    }

    cout << total_sum << endl;
}