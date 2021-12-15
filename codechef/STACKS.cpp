#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, ai;
        vector<int> stacks;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> ai;
            auto gt = upper_bound(stacks.begin(), stacks.end(), ai);
            if (gt == stacks.end()) {
                stacks.push_back(ai);
            } else {
                int idx = gt - stacks.begin();
                stacks[idx] = ai;
            }
        }

        cout << stacks.size() << " ";
        for (int i = 0; i < stacks.size(); i++) {
            cout << stacks[i] << " ";
        }
        cout << endl;
    }
}
