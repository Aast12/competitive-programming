#include <iostream>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        
        int aux, aux_p, count = 0;
        bool diffs[n];
        for (int i = 0; i < n; i++) diffs[i] = false;

        for (int i = 0; i < n; i++) {
            cin >> aux;
            if (i != 0) {
                int ins = abs(aux_p - aux);
                if (ins >= 1 && ins < n && !diffs[ins]) {
                    diffs[ins] = true;
                    count++;
                }
            }
            aux_p = aux;
        }

        if (count == n - 1) cout << "Jolly\n";
        else cout << "Not jolly\n"; 

    }
}