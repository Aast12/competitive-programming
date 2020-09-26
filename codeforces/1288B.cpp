#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull n;
    cin >> n;
    while (n--) {
        ull a, b;
        cin >> a >> b;
        ull b_dig = ull(log10(b) + 1) - 1;

        cout << a * (b_dig + (ull(log10(b + 1)) == log10(b + 1))) << endl;
    } 
}
