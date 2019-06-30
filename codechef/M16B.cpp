#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string num1, num2;
        cin >> num1 >> num2;

        if (num1 == num2) {
            cout << num1 << endl;
        } else {
            cout << 1 << endl;
        }
    }
    
}