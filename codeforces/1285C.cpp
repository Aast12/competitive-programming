#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;
typedef long long lli;

lli lcm(lli a, lli b) {
    return a / __gcd(a, b) * b;
}

int main() {
    lli X;
    cin >> X;
    lli min_max = -1;
    lli ans = 1;
    for (int i = 1; i < int(sqrt(X)); i++) {
        if (X % i == 0 && lcm(i, X / i) == X) {
           if (i > min_max) {
               min_max = i;
               ans = i;
           }
        }   
    }
    cout << ans << " " << X / ans << endl;
}