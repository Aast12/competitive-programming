#include <iostream>

using namespace std;

int main() {
    int n, vi;
    cin >> n;
    int sums[] = {0, 0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> vi;
            sums[j] += vi;
        }
    }
    
    cout << ((!sums[0] && !sums[1] && !sums[2]) ? "YES" : "NO") << endl;
}