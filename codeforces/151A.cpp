#include <iostream>

using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    int min_drinks = 0;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    min_drinks = min((k * l) / nl, min(c * d, p / np));

    cout << min_drinks / n << endl;
}