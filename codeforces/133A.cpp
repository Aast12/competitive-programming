#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool outputs = false;
    for (auto &ch : s) {
       if (ch == 'H' || ch == 'Q' || ch == '9') {
           outputs = true;
           break;
       } 
    }

    cout << (outputs ? "YES" : "NO") << endl;
}