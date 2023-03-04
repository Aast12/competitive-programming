#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int OUT_OF_BOUNDS = -2;
const int NO_ZERO = -1;

pair<int, int> get_max(vector<int> &a, int lo) {
    int n = a.size();
    if (lo >= n) return make_pair(-1, OUT_OF_BOUNDS);
    vector<int> found_idx(n - lo + 5, 0);
    int min_found_idx = NO_ZERO, next_min = 0;

    for (int i = lo; i < n; i++) {
        if (!found_idx[a[i]]) {
            found_idx[a[i]] = i + 1;
            if (next_min == a[i]) {
                min_found_idx = i;
                while (found_idx[next_min]) {
                    next_min++;
                }
            }
        }
    }

    if (min_found_idx >= 0) return make_pair(next_min, min_found_idx + 1);
    return make_pair(next_min, min_found_idx);
}

int main() {
    int t, n, max_no, max_idx;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int lo = 0;
        pair<int, int> ret;
        vector<int> ans;
        while (lo >= 0) {
            ret = get_max(a, lo);
            if (ret.first >= 0) ans.push_back(ret.first);
            lo = ret.second;
        }

        cout << ans.size() << endl;
        for (int &v : ans) {
            cout << v << " ";
        }

        cout << endl;
    }
}
