#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double p = double(a) / b, q = (1 - double(c) / d) * (1 - double(a) / b);
    cout << p / (1 - q) << endl;
}