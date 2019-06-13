#include <iostream>
#include <string.h>
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main() {
    io;
    int t, n, m, aux;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        bool dreams[n];
        memset(dreams, 0, n);
        for (int i = 0; i < m; i++){
            cin >> aux;
            dreams[aux - 1] = 1;
        }
        for (int i = 0; i < n; i++){
            if (!dreams[i]) cout << i + 1 << " ";
        }
        cout << '\n';
    }
}