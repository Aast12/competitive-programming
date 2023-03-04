#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int> &A, int lo, int up, int target) {
    if (lo >= up) {
        if (lo < up && A[lo] < target) lo++;
        return lo;
    }
    int mid = lo + (up - lo) / 2;

    if (target <= A[mid])
        return lowerBound(A, lo, mid, target);
    else
        return lowerBound(A, mid + 1, up, target);
}

int upperBound(vector<int> &A, int lo, int up, int target) {
    return lowerBound(A, lo, up, target + 1);
}

int main() {
    int n, m;

    cin >> n;
    vector<int> a0(n);
    for (int i = 0; i < n; i++) cin >> a0[i];

    cin >> m;
    vector<int> a1(m);
    for (int i = 0; i < m; i++) cin >> a1[i];

    sort(a0.begin(), a0.end());

    for (int ai : a1) {
        int lo_bound = lowerBound(a0, 0, n, ai),
            up_bound = upperBound(a0, 0, n, ai);

        cout << up_bound - lo_bound << endl;
    }
}