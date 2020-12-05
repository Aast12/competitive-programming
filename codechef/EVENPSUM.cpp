#include <math.h>

#include <iostream>

using namespace std;

int main() {
    unsigned long long t, a, b;
    cin >> t;

    while (t--) {
        cin >> a >> b;

        cout << a * b - (a / 2) * (b / 2 + b % 2) - (a / 2 + a % 2) * (b / 2) << endl;
    }
}