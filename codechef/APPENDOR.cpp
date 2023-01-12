// AC
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string intobin(int n) {
    string binary = "";

    while (n > 0) {
        binary = binary + char(n % 2 + '0');
        n >>= 1;
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

int bintoint(string n) {
    int value = 0;
    int power = 1;

    for (int i = n.size() - 1; i >= 0; i--) {
        if (n[i] == '1') {
            value += power;
        }

        power <<= 1;
    }

    return value;
}

int main() {
    int t, n, y;
    cin >> t;

    while (t--) {
        cin >> n >> y;

        vector<int> arr(n);
        int or_value = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            or_value = or_value | arr[i];
        }

        string or_value_bin = intobin(or_value);
        string y_value_bin = intobin(y);

        if (or_value_bin.size() > y_value_bin.size()) {
            cout << -1 << endl;
            continue;
        }

        or_value_bin.insert(or_value_bin.begin(),
                            y_value_bin.size() - or_value_bin.size(), '0');

        string candidate(or_value_bin.size(), '0');

        bool pos = true;
        for (int i = 0; i < y_value_bin.size(); i++) {
            if (y_value_bin[i] == '1') {
                if (or_value_bin[i] == '0') candidate[i] = '1';
            } else {
                if (or_value_bin[i] == '1') {
                    pos = false;
                    break;
                }
            }
        }

        if (!pos)
            cout << -1 << endl;
        else {
            cout << bintoint(candidate) << endl;
        }
    }

    return 0;
}
