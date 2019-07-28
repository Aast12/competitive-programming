#include <iostream>

using namespace std;

int sum_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n, val;
    cin >> n;
    while (true) {
        val = sum_digits(n);
        if (val % 4 == 0) {
            cout << n << endl;
            break;
        } else {
            n++;
        }
    }
}