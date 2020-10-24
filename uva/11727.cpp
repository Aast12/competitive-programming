#include <iostream>

using namespace std;

int main() {
    int t, a, b, c, sum;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        sum = 0;
        cin >> a >> b >> c;
        sum = a + b + c;
        
        cout << "Case " << i << ": " << sum - max(a, max(b, c)) - min(a, min(b, c)) << endl;
    }
}