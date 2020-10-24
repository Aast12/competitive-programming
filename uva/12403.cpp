#include <iostream>

using namespace std;

int main() {
    int n, amt, total = 0;
    string op;
    cin >> n;
    
    while (n--) {
        cin >> op;
        if (op == "donate") {
            cin >> amt;
            total += amt;
        } else {
            cout << total << endl;
        }
    }
}