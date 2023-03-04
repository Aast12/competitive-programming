#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, last_max;
    cin >> n;

    vector<int> seq;
    for (int i = 0; i < n; i++) {
        cin >> a;

        if (i == 0 || a > last_max) {
            seq.push_back(a);
            last_max = a;
        }
    }

    cout << seq.size() << endl;
    for (auto item : seq)
        cout << item << " ";

    cout << endl;
}