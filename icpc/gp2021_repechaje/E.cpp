#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long lli;

vector<lli> solve(lli n, lli m) {
    vector<lli> values;
    while (true) {
        lli pow = 1 << (lli(log2(n)));
        values.push_back(pow * m);
        n -= pow;
        if (n <= 0) {
            break;
        }
    }

    return values;
}

void print_index(vector<lli> &ans, int i, int last) {
    cout << ans[i];
    if (i == last)
        cout << endl;
    else
        cout << " + ";
}

void printcase(int caseno, lli n, lli m) {
    cout << "Case " << caseno << ": " << n << " x " << m << " = ";
}

int main() {
    lli n, m;
    int caseno = 1;
    char dir;

    while (true) {
        cin >> n;
        if (n == -1) break;
        cin >> m >> dir;

        printcase(caseno, n, m);
        caseno++;
        if (n == 0 || m == 0) {
            cout << 0 << endl;
            continue;
        }

        vector<lli> ans = solve(n, m);

        int len = ans.size();
        if (dir == 'b')
            for (int i = 0; i < len; i++) print_index(ans, i, len - 1);
        else
            for (int i = len - 1; i >= 0; i--) print_index(ans, i, 0);
    }
}