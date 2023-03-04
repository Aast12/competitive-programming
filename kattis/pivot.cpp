#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n], min_q[n], max_q[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    min_q[n - 1] = arr[n - 1];
    max_q[0] = arr[0];
    for (int i = 1; i < n; i++) {
        max_q[i] = max(max_q[i - 1], arr[i]);
        min_q[n - i - 1] = min(min_q[n - i], arr[n - i - 1]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((i == 0 || arr[i] > max_q[i - 1]) &&
            (i == n - 1 || arr[i] < min_q[i + 1])) {
            count++;
        }
    }

    cout << count << endl;
}