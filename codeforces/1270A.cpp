// OK
#include <iostream>

using namespace std;

int main() {
    int t, n, k1, k2, max_val, aux;
    bool first_has_max;
    cin >> t;
    while (t--) {
        max_val = 0;
        first_has_max = 0;
        cin >> n >> k1 >> k2;
        for (int i = 0; i < k1; i++) {
            cin >> aux;
            if (aux > max_val) {
                max_val = aux;
                first_has_max = 1;
            }
        }
        for (int i = 0; i < k1; i++) {
            cin >> aux;
            if (aux > max_val) {
                max_val = aux;
                first_has_max = 0;
            }
        }
        cout << ((first_has_max) ?  "YES" : "NO") << endl;
    }
}