#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < (1 << n); i++) {
        for (int d = n - 1; d >= 0; d--) {
            if (i & (1 << d))
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
}