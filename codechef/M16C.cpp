//PENDING
#include <cstdio>

using namespace std;
typedef unsigned long long ull;

int main() {
    ull Ti;
    scanf("%llu", &Ti);

    while (Ti--) {
        ull T, M, S, P, nt, nm, ns, np, pt, pm, ps, pp, R;
        scanf("%llu %llu %llu %llu", &T, &M, &S, &P);
        scanf("%llu %llu %llu %llu", &nt, &nm, &ns, &np);
        scanf("%llu %llu %llu %llu %llu", &pt, &pm, &ps, &pp, &R);

        ull curr = 100000;
        if (T != 0)curr = nt / T;
        if (M != 0 && nm / M < curr) curr = nm / M;
        if (S != 0 && ns / S < curr) curr = ns / S;
        if (P != 0 && np / P < curr) curr = np / P;
        nt -= curr * T;
        nm -= curr * M;
        ns -= curr * S;
        np -= curr * P;
        
        ull net = (T > nt) ? T - nt : 0;
        ull nem = (M > nm) ? M - nm : 0;
        ull nes = (S > ns) ? S - ns : 0;
        ull nep = (P > np) ? P - np : 0;

        if (net * pt + nem * pm + nes * ps + nep * pp <= R) {
            curr++;
            p
            R -= net * pt + nem * pm + nes * ps + nep * pp;
        }

        ull t_price = T * pt + M * pm + S * ps + P * pp;

        curr += R / t_price;
        printf("%llu", curr);
        //cout << curr << endl;

    }
}