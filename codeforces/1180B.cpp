#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n], n_nums[n], max_m = 0, max_i = 0, sign = 0;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] == 0 || nums[i] == -1) {
            n_nums[i] = -1;
        }
        else {
            int a_n = abs(nums[i]), a_m = abs(-1 - nums[i]);
            if (a_n > a_m) {
                n_nums[i] = nums[i];
                if (a_m > abs(max_m)) {
                    max_m = -1 - nums[i];
                    max_i = i;
                }
            } else {
                n_nums[i] = -1 - nums[i];
                if (a_n > abs(max_m)) {
                    max_m = nums[i];
                    max_i = i;
                }
            }
        }

        if (n_nums[i] < 0) sign++;
    }

    if (sign % 2) n_nums[max_i] = max_m;
    
    for (int i = 0; i < n; i++) cout << n_nums[i] << " ";
    cout << endl;
 
}