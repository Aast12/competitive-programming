#include <math.h>

#include <iostream>
using namespace std;

int main() {
    int d1, v1, d2, v2, p;
    cin >> d1 >> v1 >> d2 >> v2 >> p;

    if (d1 > d2) {
        swap(d1, d2);
        swap(v1, v2);
    }

    if (v1 * (d2 - d1) >= p) {
        cout << (p + d1 * v1 - v1) / v1 << endl;
    } else {
        cout << ceil((p + d1 * v1 - v1 + d2 * v2 - v2) / float(v1 + v2)) << endl;
    }
}