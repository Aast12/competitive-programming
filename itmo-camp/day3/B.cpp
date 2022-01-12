#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int subs_len, last_index;

    Node() {}
    Node(int l, int i) : subs_len(l), last_index(i) {}
};

int main() {
    int n;
    cin >> n;

    vector<int> items(n);
    vector<Node> ans(n);

    int max_len = 1, max_idx = 0;
    for (int i = 0; i < n; i++) {
        cin >> items[i];
        ans[i] = Node(1, i);
        for (int j = 0; j < i; j++) {
            if (items[j] < items[i] && ans[i].subs_len < ans[j].subs_len + 1) {
                ans[i].subs_len = ans[j].subs_len + 1;
                ans[i].last_index = j;
                if (ans[i].subs_len > max_len) {
                    max_len = ans[i].subs_len;
                    max_idx = i;
                }
            }
        }
    }

    vector<int> subsequence;
    int curr_idx = max_idx;
    while (true) {
        subsequence.push_back(items[curr_idx]);
        if (ans[curr_idx].last_index == curr_idx) break;

        curr_idx = ans[curr_idx].last_index;
    }

    cout << max_len << endl;
    for (int i = subsequence.size() - 1; i >= 0; i--) {
        cout << subsequence[i] << ' ';
    }
    cout << endl;
}
