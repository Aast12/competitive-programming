#include <stdlib.h>

#include <cmath>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
    cin.tie(0);
    int t, n;
    string s;
    cin >> t;

    while (t--) {
        cin >> n >> s;
        int x = 0, y = 0;

        int max_x = 0, max_y = 0;
        int x_count[n], y_count[n];

        if (s[0] == '0') {
            x_count[0] = 1;
            max_x = 1;
            x++;
            y_count[0] = 0;
        } else {
            y++;
            max_y = 1;
            x_count[0] = 0;
            y_count[0] = 1;
        }

        for (int i = 1; i < s.size(); i++) {
            char ch = s[i];
            char last = s[i - 1];

            if (ch == '0') {
                x++;
                y_count[i] = 0;
                x_count[i] = x_count[i - 1] + 1;
            } else {
                y++;
                x_count[i] = 0;
                y_count[i] = y_count[i - 1] + 1;
            }

            max_x = max(max_x, x_count[i]);
            max_y = max(max_y, y_count[i]);
        }

        ull sq_cont_x = max_x * max_x;
        ull sq_cont_y = max_y * max_y;

        ull max_cost = max(ull(x) * y, max(sq_cont_x, sq_cont_y));

        cout << max_cost << endl;
    }
}