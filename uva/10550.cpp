#include <iostream>

using namespace std;

int main() {
    int initial, a, b, c, degs = 0;
    while (cin >> initial >> a >> b >> c) {
        if (initial + a + b + c == 0) break;
        degs = 360 * 3; 
        if (a <= initial) degs += (initial - a) * 9;
        else degs += (initial + 40 - a) * 9;

        if (a <= b) degs += (b - a) * 9;
        else degs += (b + 40 - a) * 9;
        
        if (c <= b) degs += (b - c) * 9;
        else degs += (b + 40 - c) * 9;

        cout << degs << endl;
    }
}
