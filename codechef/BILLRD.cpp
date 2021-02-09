#include <iostream>
#include <vector>

using namespace std;

struct Vec {
    int x, y;
    Vec(int x_, int y_) : x(x_), y(y_) {}
    Vec() {}
};

int main() {
    int t, n, k, x0, y0;
    cin >> t;

    while (t--) {
        cin >> n >> k >> x0 >> y0;

        vector<Vec> points;

        int line_i = y0 - x0;

        if (line_i > 0) {
            points = {Vec(n - line_i, n),
                      Vec(n, n - line_i),
                      Vec(line_i, 0),
                      Vec(0, line_i)};
        } else if (line_i < 0) {
            line_i *= -1;
            points = {Vec(n, n - line_i),
                      Vec(n - line_i, n),
                      Vec(0, line_i),
                      Vec(line_i, 0)};
        } else {
            cout << n << " " << n << endl;
            continue;
        }

        Vec ans = points[(k - 1) % 4];
        cout << ans.x << " " << ans.y << endl;
    }
}