#include <iostream>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    s--;
    bool t1[n], t2[n];
    for (int i = 0; i < n; i++) {
        cin >> t1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t2[i];
    }
    bool flag = 0;
    if (t1[0] != 0) {
        if (t1[s] == 1) flag = 1;
        else if (t2[s] != 0) {
            for (int i = s; i < n; i++) {
                if (t1[i] && t2[i]) {
                    flag = 1;
                    break;
                }
            }
        }
    }
    cout << (flag ? "YES\n" : "NO\n");
}