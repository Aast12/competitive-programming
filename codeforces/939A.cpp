#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int planes[n];
    bool found = false;

    for (int i = 0; i < n; i++) {
        cin >> planes[i];
        planes[i]--;
    }

    for (int i = 0; i < n; i++) {
        int curr = i;
        if (planes[planes[planes[curr]]] = curr) {
            found = true;
            cout << "-> " << curr +1 << " -> " << planes[curr]+1 << " -> " << planes[planes[curr]]+1 << " -> " << 1+planes[planes[planes[curr]]] << endl; 
        }
    }

    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;
}