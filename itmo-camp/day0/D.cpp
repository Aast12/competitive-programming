#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> seq(n);

    for (int i = 0; i < n; i++) cin >> seq[i];
    for (int i = n - 1; i >= 0; i--) cout << seq[i] << (i > 0 ? ' ' : '\n');
}