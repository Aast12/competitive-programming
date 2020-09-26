#include <iostream>

using namespace std;

int main() {
    int x, y, o;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> o;
            if (o == 1) {
                x = j;
                y = i;
            }
        }
    }

    cout << abs(x - 2) + abs(y - 2) << endl;
}