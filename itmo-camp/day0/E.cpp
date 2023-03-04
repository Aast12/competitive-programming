#include <iostream>

using namespace std;

int main() {
    string expr;
    cin >> expr;

    for (auto current : expr) {
        if (current >= '0' && current <= '9')
            cout << current;
        else
            cout << ' ' << current << ' ';
    }
    cout << endl;
}