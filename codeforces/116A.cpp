#include <iostream>

using namespace std;

int main() {
    int n, a, b, current = 0, max = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        current += b - a;
        if (current > max) max = current;
    }

    cout << max << endl;
}