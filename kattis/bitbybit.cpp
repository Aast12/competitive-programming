#include <iostream>
#include <vector>
#define UNK 2

using namespace std;

int main() {
    int n, i, j;
    string cmd;

    while (cin >> n) {
        if (n == 0) break;

        vector<short> reg(32, UNK);

        while (n--) {
            cin >> cmd;

            if (cmd == "SET") {
                cin >> i;
                reg[i] = 1;
            } else if (cmd == "CLEAR") {
                cin >> i;
                reg[i] = 0;
            } else if (cmd == "OR") {
                cin >> i >> j;
                if (reg[i] == UNK || reg[j] == UNK) {
                    reg[i] = (min(reg[i], reg[j]) == 1) ? 1 : UNK;
                } else {
                    reg[i] = reg[i] | reg[j];
                }
            } else if (cmd == "AND") {
                cin >> i >> j;
                if (reg[i] == UNK || reg[j] == UNK) {
                    reg[i] = (min(reg[i], reg[j]) == 0) ? 0 : UNK;
                } else {
                    reg[i] = reg[i] & reg[j];
                }
            }
        }

        for (int i = 31; i >= 0; i--) {
            cout << char(reg[i] == UNK ? '?' : (reg[i] + '0'));
        }
        cout << endl;
    }
}