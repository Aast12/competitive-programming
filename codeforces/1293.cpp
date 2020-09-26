#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double n;
    cin >> n;
    double sum = 0;
    double prev = 1;
    for (double i = 0; i < n; i++) {
        sum += 1.00 / (i + 1);
    }
    cout << fixed << setprecision(12) << sum;
}