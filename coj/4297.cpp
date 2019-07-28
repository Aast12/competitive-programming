#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    unsigned long long t, r, k, nr;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld", &r, &k);
        nr = pow(2, (k / 2) + (k % 2) - 1) * r * r;
        if (k % 2) printf("%lldPI\n", (unsigned long long) nr);
        else printf("%lld\n", 4 * (unsigned long long) nr);
    }
}