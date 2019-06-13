#include <stdio.h>
using namespace std;

int main() {
    int N, aux, min_ = 0, max_ = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &aux);
        if (!i) {
            min_ = aux;
            max_ = aux;
        }
        if (aux < min_) min_ = aux;
        if (aux > max_) max_ = aux;
        printf("%d\n", max_ + min_);
    }
}