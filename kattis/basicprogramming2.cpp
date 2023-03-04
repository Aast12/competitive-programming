#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n;
    cin >> n >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    switch (t) {
        case 1:
            for (int i = 0; i < n; i++) {
                int target = 7777 - arr[i];
                if (binary_search(arr.begin(), arr.end(), target)) {
                    cout << "Yes\n";
                    return 0;
                }
            }
            cout << "No\n";
            return 0;
        case 2:
            for (int i = 1; i < n; i++) {
                if (arr[i] == arr[i - 1]) {
                    cout << "Contains duplicate\n";
                    return 0;
                }
            }

            cout << "Unique\n";
            return 0;
        case 3:
            if (arr[n / 2] == arr[0]) {
                cout << arr[0] << endl;
            } else {
                cout << -1 << endl;
            }
            return 0;
        case 4:
            if (n & 1)
                cout << arr[n / 2] << endl;
            else
                cout << arr[n / 2 - 1] << " " << arr[n / 2] << endl;

            return 0;
        case 5:
            auto lower = lower_bound(arr.begin(), arr.end(), 100);
            for (; lower != arr.end() && *lower < 1000; lower++) {
                cout << *lower << " ";
            }
            cout << endl;
    }
}