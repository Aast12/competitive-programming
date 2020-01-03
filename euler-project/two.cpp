#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int fib_1 = 1, fib_2 = 1, tmp;
    while(fib_2 <= 4000000) {
        if (fib_2 % 2 == 0) {
            sum += fib_2;
        }
        tmp = fib_1;
        fib_1 = fib_2;
        fib_2 = tmp + fib_2;
        cout << fib_2 << " ";
    }
    cout << endl << sum << endl;
}