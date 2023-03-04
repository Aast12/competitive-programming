#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, m, drop_acc;
    string cmd;
    while (cin >> n) {
        if (n == 0) break;

        int p1 = 0, p2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> cmd >> m;
            if (cmd == "DROP") {
                cout << "DROP 2 " << m << endl;
                p2 += m;
            } else {
                if (p1 >= m) {
                    cout << "TAKE 1 " << m << endl;
                    p1 -= m;
                } else {
                    if (p1 > 0) 
                        cout << "TAKE 1 " << p1 << endl;
                    cout << "MOVE 2->1 " << p2 << endl;
                    cout << "TAKE 1 " << m - p1 << endl;
                    p1 = p2 - (m - p1);
                    p2 = 0;
                }
            }
        }
        cout << endl;
    }
}