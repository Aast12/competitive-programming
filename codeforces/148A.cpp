#include <iostream>

using namespace std;

int main() {
    int multiples[4], d;
    for (int i = 0; i < 4; i++) {
        cin >> multiples[i];
    }
    cin >> d;

    int total = 0;
    
    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < 4; j++) {
            if (i % multiples[j] == 0) {
                total++;
                break;
            }
        }
    }

    cout << total << endl;

}