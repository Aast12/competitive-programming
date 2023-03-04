#include <iostream>

using namespace std;

int main() {
    string n, m;  // n / m

    cin >> n >> m;

    int zero_count = m.size() - 1;
    int integer_digits = max(int(n.size()) - zero_count, 0);
    if (integer_digits <= 0)
        cout << 0;
    else
        cout << n.substr(0, integer_digits);

    int frac_digits = n.size() - integer_digits;
    string fraction = n.substr(integer_digits, frac_digits);

    fraction.insert(fraction.begin(), zero_count - frac_digits, '0');

    bool found = 0;
    for (int i = fraction.size() - 1; i >= 0; i--) {
        if (fraction[i] != '0') {
            fraction = fraction.substr(0, i + 1);
            found = true;
            break;
        }
    }

    if (found) cout << '.' << fraction << endl;
}