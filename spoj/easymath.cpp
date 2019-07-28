#include <iostream>

using namespace std;

int main() {
    int t, n, m, a, d;
    while (t--) {
        int div_nums = 0;
        cin >> n >> m >> a >> d;
        div_nums += m / a + m / (a + d) + m / (a + 2 * d) + m / (a + 3 * d) + m / (a + 4 * d);
        div_nums -= n / a + n / (a + d) + n / (a + 2 * d) + n / (a + 3 * d) + n / (a + 4 * d);

        cout << (m - n) - div_nums;
    }
}