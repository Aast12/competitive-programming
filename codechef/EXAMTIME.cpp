#include <iostream>

using namespace std;

int main() {
    int t, dragon[4], sloth[4], total;
    cin >> t;

    while (t--) {
        total = 0;
        for (int i = 0; i < 3; i++) {
            cin >> dragon[i + 1];
            total += dragon[i + 1];
        }
        dragon[0] = total;

        total = 0;
        for (int i = 0; i < 3; i++) {
            cin >> sloth[i + 1];
            total += sloth[i + 1];
        }
        sloth[0] = total;

        for (int i = 0; i < 4; i++) {
            if (dragon[i] > sloth[i]) {
                cout << "DRAGON\n";
                break;
            } else if (dragon[i] < sloth[i]) {
                cout << "SLOTH\n";
                break;
            }

            if (i == 3) cout << "TIE\n";
        }
    }
}