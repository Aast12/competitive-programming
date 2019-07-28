#include <cstdio>

typedef long long ull;

using namespace std;

ull inv = 0;
void Merge(ull A[], ull p, ull q, ull r) {
    ull n1 = q - p + 1;
    ull n2 = r - q;
    ull L[n1 + 1], R[n2 + 1], i, j;
    for (i = 0; i < n1; i++) {
        if (p + i <= r) L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++) {
        if (q + j + 1 <= r) R[j] = A[q + j + 1];
    } 
    L[n1] = -1;
    R[n2] = -1;
    i = 0;
    j = 0;
    for (ull k = p; k <= r; k++) {   
        if ((L[i] != -1) && (L[i] <= R[j] || R[j] == -1)) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
            inv += n1 - i;
        }
    }
}

void MergeSort(ull A[], ull p, ull r) {
    if (p < r) {
        ull q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main() {
    int n;
    while(scanf("%d", &n)) {
        inv = 0;
        if (n == 0) break;
        ull *A = new ull[n];
        for (ull i = 0; i < n; i++) scanf("%lld", &A[i]);
        MergeSort(A, 0, n - 1);
        printf("%lld", inv);
        delete[] A;
        A = nullptr;
    }
}
