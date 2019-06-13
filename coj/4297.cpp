//PENDING
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int t, r, k, nr;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &r, &k);
        nr = r;
        for (int i = 0; i < (k / 2) - 1; i++) {
            nr = 2 * nr * nr;
        }
        if (k % 2) {
            nr = 2 * nr * nr;
            printf("%dPI\n", nr);
        } else {
            if (k == 2) nr *= nr;
            printf("%d\n", 4 * nr);
        }
    }
}