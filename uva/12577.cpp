#include <iostream>

using namespace std;

int main() {
    int caseno = 0;
    string type;

    while (cin >> type) {
        if (type == "*") break;
        caseno++;

        if (type == "Hajj") {
            cout << "Case " << caseno << ": Hajj-e-Akbar" << endl;
        } else {
            cout << "Case " << caseno << ": Hajj-e-Asghar" << endl;
        }
    }
}