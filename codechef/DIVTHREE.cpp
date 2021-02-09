#include <iostream>

using namespace std;

int main() {
    long t, n, k, d, a_i, problems;
    cin >> t;

    while (t--) {
        problems = 0;

        cin >> n >> k >> d;

        for (int i = 0; i < n; i++) {
            cin >> a_i;
            problems += a_i;
        }

        cout << min(problems / k, d) << endl;
    }
}