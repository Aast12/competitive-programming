#include <iostream>
#include <unordered_set>
#include <vector>


using namespace std;

int main() {
    int t, n, m;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        int p[m], offset = 1, tail = n - 1;
        vector<int> ans(n, -1);
        unordered_set<int> in_field;
        
        cin >> p[0];
        ans[tail--] = 1;
        in_field.insert(p[0]);
        
        for (int i = 1; i < m; i++) {
            cin >> p[i];
            if (tail < 0) continue;
            if (in_field.find(p[i]) != in_field.end()) {
                offset++;
            } else {
                ans[tail--] = ++offset;
                in_field.insert(p[i]);
            }
        }

        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}