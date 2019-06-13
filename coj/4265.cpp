#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    long digits = 0, a, b, t;
    scanf("%ld", &t);
    while (t--) {
        digits = 0;
        scanf("%ld %ld", &a, &b);
        digits += (a >= b) ? b : a;
        a -= digits;
        b -= digits;
        digits += a * log10(2) + 1;
        digits += b * log10(5) + 1;
        printf("%ld\n", digits - 1);
    }
}