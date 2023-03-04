#include <cmath>
#include <iostream>

using namespace std;

int calc_sum(string &s, int i) {
    int fst = s[i] - '0', snd = s[i + 1] - '0';
    int sum = fst + snd;

    return sum;
}

int calc_diff(string &s, int i) {
    int k = s.size() - i - 1;
    return (s[i] - '0') * pow(10, k - 1) * 9;
}

int main() {
    int t;
    string s;
    cin >> t;

    while (t--) {
        cin >> s;
        int ans_idx = s.size() - 2;
        int min_diff = calc_diff(s, ans_idx);
        int ans = calc_sum(s, ans_idx);

        for (int i = 0, k = ans_idx - 1; i < 5 && k >= 0; i++, k--) {
            int sum = calc_sum(s, i);
            if (sum >= 10) {
                int candidate = calc_diff(s, k);
                if (candidate < min_diff) {
                    min_diff = candidate;
                    ans_idx = k;
                    ans = sum;
                }
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (i == ans_idx) {
                cout << ans;
                i++;
            } else {
                cout << s[i];
            }
        }

        cout << endl;
    }
}