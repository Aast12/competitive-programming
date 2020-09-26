#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    n++;

    for (int i = n; n <= i + 1000; i++) {
        vector<int> digits(10, 0);
        for (int j = 1, k = 0; k < 4; k++, j *= 10) {
            int dig = (i / j) % 10;
            digits[dig]++;
            if (digits[dig] > 1) {
                break;
            }
            if (k == 3) {
                cout << i << endl;
                return 0;
            }
        }
    }

}