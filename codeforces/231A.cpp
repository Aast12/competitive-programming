#include <iostream>

using namespace std;

int main() {
    int n, p, solutions = 0;
    cin >> n;

    while (n--) {
        for (int i = 0, c = 0; i < 3; i++) {
            cin >> p;
            if (p) c++;
            if (i == 2 && c >= 2) solutions++;
        }
    }

    cout << solutions << endl;
}