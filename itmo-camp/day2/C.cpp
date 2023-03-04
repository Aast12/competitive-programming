#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a_i;
    const int BOUND = 101;
    vector<int> A, counts(BOUND);

    while (cin >> a_i) {
        A.push_back(a_i);
        counts[a_i]++;
    }

    for (int i = 0; i < BOUND; i++) {
        while (counts[i]--) {
            cout << i << " ";
        }
    }
    cout << endl;
}