#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int t, n, d, a, risk_count;
    cin >> t;

    while (t--) {
        risk_count = 0;
        cin >> n >> d;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (a <= 9 || a >= 80) risk_count++;
        }

        cout << ceil(risk_count / double(d)) + ceil((n - risk_count) / double(d)) << endl;
    }
}
