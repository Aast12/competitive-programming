#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

pair<int, vi> calc_prefix_func(string s, int target_size) {
    int n = s.size();
    vi pi(n, 0);

    int complete_count = 0;
    for (int i = 1; i < n; i++) {
        int x = pi[i - 1];
        while (s[i] != s[x] && x > 0) x = pi[x - 1];

        if (s[i] == s[x]) x++;

        pi[i] = x;
        if (pi[i] == target_size) 
            complete_count++;
    }

    return make_pair(complete_count, pi);
}

int main() {
    string s, prefix;
    cin >> prefix >> s;

    int n = s.size(), p = prefix.size();
    auto pi_obj = calc_prefix_func(prefix + '#' + s, p);
    vi pi = pi_obj.second;
    cout << pi_obj.first << endl;
    for (int i = 0; i < pi.size(); i++) {
        if (pi[i] == p) {
            cout << i - 2 * p + 1 << " ";
        }
    }

    cout << endl;
}
