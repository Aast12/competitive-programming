#include <iostream>

using namespace std;

int modProd(int a, int b, int m) {
    return (int)((long long) a * b % m);
}

int modPow(int a, int b, int m) {
    if (b == 0) return 1;

    int sub = modPow(a, b / 2, m);
    int result = modProd(sub, sub, m);
    if (b % 2 == 1) {
        result = modProd(result, a, m);
    }

    return result;
}

int main() {
    int a, b, m;
    cin >> a >> b >> m;

    cout << modPow(a, b, m) << endl;
}