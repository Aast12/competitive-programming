#include <iostream>

using namespace std;

bool set[100005];

int main() {
    int n, m, l;
    cin >> n >> m;

    int nums[n], distinct_count[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    distinct_count[n - 1] = 1;
    set[nums[n - 1]] = 1;
    for (int i = n - 2; i >= 0; i--) {
        distinct_count[i] = distinct_count[i + 1];
        if (!set[nums[i]]) {
            set[nums[i]] = 1;
            distinct_count[i]++;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> l;
        cout << distinct_count[l - 1] << endl;
    }
}