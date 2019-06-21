#include <iostream>

using namespace std;

int main() {
    int n, h, i, w = 0; 
    cin >> n >> h;
    while (n--) {
        cin >> i;
        w++;
        if (i > h) w++;
    }
    cout << w << endl;
}