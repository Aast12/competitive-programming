#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int sums[4];
    for (int i = 0; i < 4; i++) cin >> sums[i];
    sort(sums, sums + 4);

    cout << sums[3] - sums[0] << " " << sums[3] - sums[1] << " " << sums[3] - sums[2] << endl;
}