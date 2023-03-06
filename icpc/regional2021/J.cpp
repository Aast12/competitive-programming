#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define OFFSET 10e6

using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> pll;

bool is_side(ull x, ull y, ull w, ull h) {
    return !((x > 0 && x < w) && (y > 0 && y < h));
}

ull encode(ull x, ull y, ull w, ull h) {
    if (x == 0 && y == 0) return 0;
    if (x == 0) return 2 * w + h + (h - y);
    if (x == w) return w + y;
    if (y == 0) return x;
    return w + h + (w - x);  // if (y == h)
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    ull w, h, x1, y1, x2, y2, t1, t2;
    int n;

    cin >> w >> h >> n;

    vector<pll> perimeter;
    bool has_v = 0, has_h = 0;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (is_side(x1, y1, w, h) && is_side(x2, y2, w, h)) {
            t1 = encode(x1, y1, w, h);
            t2 = encode(x2, y2, w, h);
            if (t1 > t2) swap(t1, t2);
            // perimeter.push_back({t1, t2});

            // if (t2 == 0) t2 == 2 * w + 2 * h;

            perimeter.push_back({t1, i});
            perimeter.push_back({t2, i + OFFSET});

            // cout << i << " -> " << char(i + 'a') << endl;

            if (t1 >= w && t1 <= w + h && t2 >= 2 * w + h &&
                t2 <= 2 * w + 2 * h)
                has_h = 1;

            if (t1 >= 0 && t1 <= w && t2 >= w + h && t2 <= 2 * w + h) has_v = 1;
        }
    }

    if (perimeter.size() == 0) {
        cout << 'Y' << endl;
        return 0;
    }

    sort(perimeter.begin(), perimeter.end(),
         [](const pll& p1, const pll& p2) { return p1.first < p2.first; });

    stack<pll> check;
    check.push(perimeter[0]);
    bool pos = 1;
    for (int i = 1; i < perimeter.size() && pos; i++) {
        pll top = check.top();
        if (perimeter[i].second < OFFSET) {
            check.push(perimeter[i]);
        } else if (perimeter[i].second - OFFSET == top.second) {
            check.pop();
        } else {
            pos = 0;
            break;
        }

    }

    cout << (pos ? 'Y' : 'N') << endl;
}