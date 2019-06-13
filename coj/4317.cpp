#include <iostream>
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main() {
    io;
    int n;
    string line;
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, line);
        for (auto &c : line) {
            cout << c;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                cout << 'p' << c;
            }
        }
        cout << '\n';       
    }
}