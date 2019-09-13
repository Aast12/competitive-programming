#include <iostream>

using namespace std;

int check(int arr[], int low, int high) {
    bool sorted = true;
    for (int i = low + 1; i < high; i++) {
        if (arr[i] < arr[i - 1]) {
            sorted = false;
            break;
        }
    }
    if (sorted) return (high - low);
    else return max(check(arr, low, (high + low) / 2), check(arr, (high + low) / 2, high));
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << check(arr, 0, n) << endl;
}