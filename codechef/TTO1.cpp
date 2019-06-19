#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];

    bool changes = true, sorted = true;
    while (changes) {
        changes = false;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > nums[i + 2]) {
                swap(nums[i], nums[i + 2]);
                changes = true;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            sorted = false;
            cout << i << endl;
            break;
        }
    }

    if (sorted) cout << "OK";
}