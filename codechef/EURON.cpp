#include <iostream>
#include <vector>

using namespace std;

typedef long long lli;
typedef vector<lli> vi;

lli merge(vi &target, vi &left, vi &right) {
    lli li = 0, ri = 0, ls = left.size(), rs = right.size(), count = 0;

    while (li < ls || ri < rs) {
        if (li == ls) {
            target[li + ri] = right[ri];
            ri++;
        } else if (ri == rs) {
            target[li + ri] = left[li];
            li++;
        } else if (left[li] <= right[ri]) {
            target[li + ri] = left[li];
            li++;
        } else {
            target[li + ri] = right[ri];
            count += ls - li;
            ri++;
        }
    }

    return count;
}

lli mergeCount(vi &arr) {
    int n = arr.size();
    if (n < 2) return 0;
    int mid = (n + 1) / 2;
    vi left = vi(arr.begin(), arr.begin() + mid);
    vi right = vi(arr.begin() + mid, arr.end());

    return mergeCount(left) + mergeCount(right) + merge(arr, left, right);
}

int main() {
    int n;
    lli ai;
    cin >> n;
    vi arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << mergeCount(arr) << endl;
}