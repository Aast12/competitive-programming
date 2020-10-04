#include <iostream>

using namespace std;

int press[10];

int main() {
    int k;
    char p;
    cin >> k;

    bool pos = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> p;
            if (p >= '0' && p <= '9') {
                press[p - '0']++;
                if (press[p - '0'] > k * 2) pos = false;
            }
        }   
    }

    cout << (pos ? "YES" : "NO") << endl;
}