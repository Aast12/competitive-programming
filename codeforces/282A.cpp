#include <iostream>

using namespace std;

int main() {
    int n, store = 0;
    string s;
    cin >> n;

    while (n--) {
        cin >> s;
        if (s[0] == '+' || s[2] == '+') {
            store++;
        } else {
            store--;
        }
    }

    cout << store << endl;
}