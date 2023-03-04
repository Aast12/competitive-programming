#include <iostream>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (arr[0] == 1)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
}