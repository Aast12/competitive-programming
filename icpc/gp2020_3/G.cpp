#include <iostream>
#include <vector>
using namespace std;

int t[4 * 100005];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int getMax(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(getMax(v * 2, tl, tm, l, min(r, tm)), getMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int main() {
    int n, g, a, b;

    cin >> n;

    int gold[n];
    pair<int, int> bounds[n];

    for (int i = 0; i < n; i++) {
        cin >> g >> a >> b;
        gold[i] = g;
        bounds[i] = make_pair(a, b);
    }

    build(gold, 1, 0, n - 1);
    int total_max = -1;
    for (int i = n - 1; i >= 0; i--) {
        a = bounds[i].first, b = bounds[i].second;
        int lb = i + a, rb = min(i + b, n - 1);

        int curr_max = gold[i];

        if (lb > i && lb < n) {
            curr_max += getMax(1, 0, n - 1, lb, rb);
            update(1, 0, n - 1, i, curr_max);
        }
        
        if (curr_max > total_max) total_max = curr_max;
    }

    cout << total_max << endl;
}