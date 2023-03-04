#include <iostream>
#include <stack>
#define INF 10e9 + 1

using namespace std;

typedef unsigned long long ull;

int main() {
    int n;
    ull h, min_h = INF, max_d = 0;
    cin >> n;

    stack<ull> height;
    for (int i = 0; i < n; i++) {
        cin >> h;

        if (height.empty()) {
            height.push(h);
            min_h = h;
        } else {
            if (h < height.top()) {
                min_h = min(min_h, h);
                max_d = max(max_d, h - min_h);
            } else {
                max_d = max(max_d, height.top() - min_h);
                height.pop();
                min_h = h;

                height.push(h);
            }
        }
    }

    cout << max_d << endl;
}