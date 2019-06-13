#include <stdio.h>
using namespace std;

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t, m, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &m, &n);
        printf("%d\n", (m * n) / gcd(m, n));
    }
}