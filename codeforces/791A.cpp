#include <iostream>

using namespace std;

int main() {
    int a, b, c = 0;
    cin >> a >> b;
    while (a <= b) {
        c++;
        a *= 3;
        b *= 2;
    }
    cout << c << endl;
}