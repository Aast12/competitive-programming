#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> segtree;
vector<int> source;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        segtree[v] = source[tl];
    } else {
        int mid = (tl + tr) / 2;
        build(v * 2, tl, mid);
        build(v * 2 + 1, mid + 1, tr);
        segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
    }
}

long long sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return segtree[v];
    }

    int mid = (tl + tr) / 2;

    return sum(v * 2, tl, mid, l, min(r, mid)) +
           sum(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
}

void update(int v, int tl, int tr, int i, int x) {
    if (tl == tr) {
        segtree[v] = x;
    } else {
        int mid = (tl + tr) / 2;
        if (i <= mid)
            update(v * 2, tl, mid, i, x);
        else
            update(v * 2 + 1, mid + 1, tr, i, x);

        segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
    }
}

int main() {
    int n;
    cin >> n;
    source = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> source[i];
    }

    segtree = vector<long long>(n * 4);

    build(1, 0, n - 1);

    string cmd;
    int left, right;

    while (cin >> cmd >> left >> right) {
        if (cmd == "sum") {
            cout << sum(1, 0, n - 1, left - 1, right - 1) << endl;
        } else {
            update(1, 0, n - 1, left - 1, right);
        }
    }
}