#include <iostream>

using namespace std;

int main() {
    int n;
    string before, after;

    cin >> n >> before >> after;

    bool shoud_equal = !(n & 1);
    for (int i = 0; i < before.size(); i++) {
        if ((before[i] == after[i] && !shoud_equal) ||
            (before[i] != after[i] && shoud_equal)) {
            cout << "Deletion failed" << endl;
            return 0;
        }
    }

    cout << "Deletion succeeded" << endl;
}