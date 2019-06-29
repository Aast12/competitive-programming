#include <iostream>

using namespace std;
typedef unsigned long long ull;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ull x, y, k;
        cin >> x >> y >> k;
        if ((x + y) / k % 2 == 0) {
            cout << "Chef" << endl;
        } else {
            cout << "Paja" << endl;
        }
    }
}