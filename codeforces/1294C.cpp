#include <iostream>
#include <cmath>
#include <vector>
#define MAX 100

using namespace std;
typedef long long lli;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        lli n;
        cin >> n;
        bool is_prime = 1, is_pos = 0;
        lli a, b, c;
        for (lli i = 2; i <= ceil(sqrt(n)); i++) {
            if (n % i == 0) {
                is_prime = 0;
                a = i;
                b = n / i;
                break;
            }
        }
        if (!is_prime) {
            for (lli i = 2; i <= ceil(sqrt(a)); i++) {
                if (a % i == 0 && a != i && a / i != b && b != i) {
                    is_pos = 1;
                    c = a / i;
                    a = i;
                    break;
                }
            }
            if (!is_pos) {
                for (lli i = 2; i <= ceil(sqrt(b)); i++) {
                    if (b % i == 0 && b != i && b / i != a && a != i && b / i != b && a != i && i != b / i) {
                        is_pos = 1;
                        c = b / i;
                        b = i;
                        break;
                    }
                }
            }
        }

        cout << ((is_pos) ? "YES" : "NO") << endl;
        if (is_pos) cout << a << " " << b << " " << c << endl;
    }
}