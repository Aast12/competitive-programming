#include <iostream>

using namespace std;

int main() {
    int n, a_val, a;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a_val;
        for (int i = 1; i < n; i++) {
            cin >> a;
            a_val |= a;
        }

        cout << a_val << " ";
    }
    cout << endl;
}