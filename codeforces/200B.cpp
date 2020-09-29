#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int pi;
    double percent = 0;
    for (int i = 0; i < n; i++) {
        cin >> pi;
        percent += pi;
    }

    cout << percent / n << endl;
}