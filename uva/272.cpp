#include <iostream>

using namespace std;

int main() {
    string line;
    bool order = 1;
    while (getline(cin, line)) {
        for (auto &ch : line) {
            if (ch == '"') {
                if (order) cout << "``";
                else cout << "''";
                order = !order;
            } else {
                cout << ch;
            }
        }
        cout << endl;
    }
}