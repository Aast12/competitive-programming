#include <iostream>

using namespace std;

int main() {
    long long a, b, c, d, moves = 0;
    cin >> a >> b >> c >> d;
    if (b > c) swap(b, c);
    if (a > c) swap(a, c);
    if (a > b) swap(a, b);
    
    if (b - a < d) moves += d - (b - a);
    if (c - b < d) moves += d - (c - b);

    cout << moves << endl;
}