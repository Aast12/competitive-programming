#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int b, s, l, r;

    while (cin >> s >> b) {
        if (b == 0 && s == 0) break;

        vector<int> left(s), right(s);

        for (int i = 0; i < s; i++) {
            int li = i - 1, ri = i + 1;

            if (li < 0)
                left[i] = -1;
            else
                left[i] = li;

            if (ri >= s)
                right[i] = -1;
            else
                right[i] = ri;
        }

        for (int i = 0; i < b; i++) {
            cin >> l >> r;
            l--;
            r--;

            int next_r = right[r];
            int next_l = left[l];

            if (next_r >= 0) left[next_r] = left[l];
            if (next_l >= 0) right[next_l] = right[r];

            int curr_left = left[l], curr_right = right[r];

            cout << (curr_left == -1 ? "*" : to_string(curr_left + 1)) << " ";
            cout << (curr_right == -1 ? "*" : to_string(curr_right + 1))
                 << "\n";
        }
        cout << "-\n";
    }
}
