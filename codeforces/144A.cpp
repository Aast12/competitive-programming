#include <iostream>
 
using namespace std;
 
int main() {
    int n, max_i = -1, min_i = -1, ans = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (max_i == -1 || (arr[i] > arr[max_i] && min_i != i)) max_i = i;
        if (min_i == -1 || (arr[i] <= arr[min_i] && max_i != i)) min_i = i;
    }
    ans += max_i;
    ans += n - min_i - 1;
    if (max_i > min_i) ans--;
    cout << ans << endl;
}